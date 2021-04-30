#include "dimensoesdialog.h"
#include "ui_dimensoesdialog.h"

DimensoesDialog::DimensoesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDimensoes)
{
    ui->setupUi(this);

}

DimensoesDialog::~DimensoesDialog()
{
    delete ui;
}

int DimensoesDialog::leDimX(){

    return ui->spinBoxX->value();
}

int DimensoesDialog::leDimY(){
    return ui->spinBoxY->value();
}

int DimensoesDialog::leDimZ(){
    return ui->spinBoxZ->value();
}
