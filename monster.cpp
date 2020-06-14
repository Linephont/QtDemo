#include "monster.h"
#include <QPixmap>
#include <QPainter>
#include <QPropertyAnimation>
Monster::Monster(QObject *parent) : QObject(parent)
{

}
Monster::Monster(QPoint _startPoi,QPoint _endPoi,QString _filepath):QObject(0),pix(_filepath)
{
    this->startPoi=_startPoi;
    this->nowPoi=_startPoi;
    this->endPoi=_endPoi;
    this->filepath=_filepath;
}
void Monster::draw(QPainter * painter,int a,int b)
{
    int x,y;
    x=nowPoi.x();
    y=nowPoi.y();
    //painter->drawPixmap(nowPoi,pix);
    painter->drawPixmap(x,y,a,b,pix);
}
void Monster::move()
{
    QPropertyAnimation* anima=new QPropertyAnimation(this,"nowPoi");
    anima->setDuration(10000);
    anima->setStartValue(startPoi);
    anima->setEndValue(endPoi);
    anima->start();



}
QPoint Monster::getnowPoi()
{
    return this->nowPoi;
}
void Monster::setnowPoi(QPoint newone)
{
    this->nowPoi=newone;
}

