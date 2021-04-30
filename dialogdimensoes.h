#ifndef DIMENSOESDIALOG_H
#define DIMENSOESDIALOG_H

#include <QDialog>
#include <QSpinBox>

namespace Ui {
class DimensoesDialog;
}

class DimensoesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DimensoesDialog(QWidget *parent = nullptr);
    ~DimensoesDialog();
    int leDimX();
    int leDimY();
    int leDimZ();

private slots:

private:
    Ui::DimensoesDialog *ui;

};

#endif // DIMENSOESDIALOG_H
