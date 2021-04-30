#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include "dialogdimensoes.h"
#include "Sculptor.h"
#include <QDebug>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    connect(ui->actionDimensoes,
            SIGNAL(triggered(bool)),
            this,
            SLOT(abreDimensoes()));
    connect(ui->actionSalvar,
            SIGNAL(triggered(bool)),
            this,
            SLOT (salvaArquivo()));

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::fecharProg(){
    exit(0);
}

void MainWindow::abreDimensoes(){
    if(d.exec()==QDialog::Accepted){
        ui->widgetDesenho->setX(d.leDimX());
        ui->widgetDesenho->setY(d.leDimY());
        ui->horizontalSliderPlanoZ->setMaximum(d.leDimZ());
        ui->widgetDesenho->dims->~Sculptor();
        ui->widgetDesenho->dims = new Sculptor(d.leDimX(),d.leDimY(),d.leDimZ());
        repaint();
    }
}

void MainWindow::desenhaVoxel(){

}

void MainWindow::salvaArquivo(){
    ui->widgetDesenho->dims->writeOFF("escultor.off");
}
