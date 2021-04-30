#include "dialogdimensoes.h"
#include "ui_dialogdimensoes.h"

DialogDimensoes::DialogDimensoes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDimensoes)
{
    ui->setupUi(this);

}

DialogDimensoes::~DialogDimensoes()
{
    delete ui;
}

int DialogDimensoes::leDimX(){

    return ui->spinBoxX->value();
}

int DialogDimensoes::leDimY(){
    return ui->spinBoxY->value();
}

int DialogDimensoes::leDimZ(){
    return ui->spinBoxZ->value();
}
