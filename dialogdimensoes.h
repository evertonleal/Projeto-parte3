#ifndef DIALOGDIMENSOES_H
#define DIALOGDIMENSOES_H

#include <QDialog>
#include <QSpinBox>

namespace Ui {
class DialogDimensoes;
}

class DialogDimensoes : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDimensoes(QWidget *parent = nullptr);
    ~DialogDimensoes();
    int leDimX();
    int leDimY();
    int leDimZ();

private slots:

private:
    Ui::DialogDimensoes *ui;

};

#endif // DIALOGDIMENSOES_H
