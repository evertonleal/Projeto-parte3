#ifndef DESENHO_H
#define DESENHO_H
#include "Sculptor.h"
#include <QWidget>

class Desenho : public QWidget
{
    Q_OBJECT
private:
    int nx=10,ny=10,nz=10;

public:
    explicit Desenho(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void setX(int);
    void setY(int);
    void setZ(int);
    Sculptor *dims;

signals:
    void posicaoMouse(int, int);

public slots:

};

#endif // DESENHO_H
