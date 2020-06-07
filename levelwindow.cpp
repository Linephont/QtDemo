#include "levelwindow.h"
#include <QPainter>
#include <QPixmap>
Levelwindow::Levelwindow(QWidget *parent) : QMainWindow(parent)
{
   this->setFixedSize(800,600);

}

void Levelwindow::paintEvent(QPaintEvent*)
{
    QPainter paint(this);
    QPixmap pix;
    pix.load(picpath);
    paint.drawPixmap(0,0,this->width(),this->height(),pix);

}
