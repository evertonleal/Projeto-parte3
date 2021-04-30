#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include "Sculptor.h"
#include "Voxel.h"
#include <QDebug>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx=_nx; ny=_ny; nz=_nz;
    v = new Voxel**[nz];
    for(int i=0;i<nx;i++){
        v[i] = new Voxel*[nx];
        for(int j=0;j<ny;j++){
            v[i][j] = new Voxel[ny];
            for(int k=0;k<nz;k++){
                v[i][j][k].isOn = false;
            }
        }
    }
    qDebug() << "Sculptor criado!";
    qDebug() << "Dimensão x: " << nx;
};

Sculptor::~Sculptor(){
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            delete [] v[i][j];
        }
        delete [] v[i];
    }
    delete [] v;
};

void Sculptor::setColor(float r, float g, float b, float alpha){
    this->r=r;
    this->g=g;
    this->b=b;
    a=alpha;
};

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
};

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
};

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if((i>=x0 && i<=x1) && (j>=y0 && j<=y1) && (k>=z0 && k<=z1)){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
};

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if((i>=x0 && i<=x1) && (j>=y0 && j<=y1) && (k>=z0 && k<=z1)){
                    v[i][j][k].isOn = false;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
};

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if((pow((i-xcenter),2)+pow((j-ycenter),2)+pow((k-zcenter),2)) <= pow(radius,2)){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
};

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if((pow((i-xcenter),2)+pow((j-ycenter),2)+pow((k-zcenter),2)) <= pow(radius,2)){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
};

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(1.0*(double((pow(((i-xcenter)/(rx*1.0)),2)+pow(((j-ycenter)/(ry*1.0)),2)+pow(((k-zcenter)/(rz*1.0)),2)))) <= 1.0){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
};

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(1.0*(double((pow(((i-xcenter)/(rx*1.0)),2)+pow(((j-ycenter)/(ry*1.0)),2)+pow(((k-zcenter)/(rz*1.0)),2)))) <= 1.0){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
};

void Sculptor::writeOFF(string filename){
    int vertices=0, faces=0;
    ofstream arquivo;
    int aux=0;
    arquivo.open(filename);
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn==true){
                    vertices+=8;
                    faces+=6;
                }
            }
        }
    }
    if(arquivo.is_open()){
        cout << "O arquivo foi aberto!" << endl;
        arquivo << "OFF" << endl;
        arquivo << vertices << " " << faces << " " << 0 << endl;
        for(int i=0;i<nx;i++){
            for(int j=0;j<ny;j++){
                for(int k=0;k<nz;k++){
                    if(v[i][j][k].isOn==true){
                        arquivo << i-0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                        arquivo << i-0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                        arquivo << i+0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                        arquivo << i+0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                        arquivo << i-0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                        arquivo << i-0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                        arquivo << i+0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                        arquivo << i+0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                    }
                }
            }
        }
        for(int i=0;i<nx;i++){
            for(int j=0;j<ny;j++){
                for(int k=0;k<nz;k++){
                    if(v[i][j][k].isOn==true){
                        arquivo << "4 " << 0+(aux*8) << " " << 3+(aux*8) << " " << 2+(aux*8) << " " << 1+(aux*8) << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                        arquivo << "4 " << 4+(aux*8) << " " << 5+(aux*8) << " " << 6+(aux*8) << " " << 7+(aux*8) << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                        arquivo << "4 " << 0+(aux*8) << " " << 1+(aux*8) << " " << 5+(aux*8) << " " << 4+(aux*8) << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                        arquivo << "4 " << 0+(aux*8) << " " << 4+(aux*8) << " " << 7+(aux*8) << " " << 3+(aux*8) << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                        arquivo << "4 " << 3+(aux*8) << " " << 7+(aux*8) << " " << 6+(aux*8) << " " << 2+(aux*8) << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                        arquivo << "4 " << 1+(aux*8) << " " << 2+(aux*8) << " " << 6+(aux*8) << " " << 5+(aux*8) << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                        aux++;
                    }
                }
            }
        }
    }else{
        cout << "Houve um erro ao abrir o arquivo!" << endl;
    }
    arquivo.close();
};
