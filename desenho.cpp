#include "desenho.h"
#include <QPainter> //criar a area do desenho
#include <QBrush> //preenchimento de aréa do desenho
#include <QPen> // contorno do desenho
#include <QMouseEvent>
#include "dialogdimensoes.h"


Desenho::Desenho(QWidget *parent) : QWidget(parent){
    dims = new Sculptor(nx,ny,nz);
    setMouseTracking(true);
}

void Desenho::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;
    brush.setColor(QColor(255,255,255)); 
    brush.setStyle(Qt::SolidPattern); 
    pen.setColor(QColor(0,0,0)); 
    pen.setWidth(2); 
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(0,0,width(),height());
    pen.setWidth(1);
    painter.setPen(pen);
    for(int i=0;i<=width();i+=width()/nx){
        for(int j=0;j<=height();j+=height()/ny){
            painter.drawRect(i,j,width()/nx,height()/ny);
        }
    }
}

void Desenho::mousePressEvent(QMouseEvent *event){
    emit posicaoMouse(event->x(), event->y());
}

void Desenho::setX(int nx){
    this->nx = nx;
}

void Desenho::setY(int ny){
    this->ny = ny;
}

void Desenho::setZ(int nz){
    this->nz = nz;
}
