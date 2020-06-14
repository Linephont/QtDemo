#include "levelwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include "tower.h"
#include "monster.h"
#include "mypushbutton.h"
Levelwindow::Levelwindow(QWidget *parent) : QMainWindow(parent)
{
   this->setFixedSize(800,600);
    this->picpath="\0";
   Mypushbutton* startlevel=new Mypushbutton(":/startlevel.png");
   startlevel->setParent(this);
   startlevel->move(400,300);
   connect(startlevel,&Mypushbutton::clicked,this,[=](){

   startlevel->hide();

   this->startmonster();
   });
   QTimer* timer=new QTimer(this);
   connect(timer,&QTimer::timeout,this,&Levelwindow::updatewindow);
   timer->start(10);
}

void Levelwindow::paintEvent(QPaintEvent*)
{
    QPainter paint(this);
    QPixmap pix;
    pix.load(picpath);
    paint.drawPixmap(0,0,this->width(),this->height(),pix);
    foreach(Monster* mon,monster_list)
        mon->draw(&paint,100,120);

}
void Levelwindow::setatower()
{
    Tower* tower01=new Tower(QPoint(250,250),":/yasina.png");
    tower_list.push_back(tower01);
    update();
}
void Levelwindow::startmonster()
{
    Monster* mon=new Monster(QPoint(35,260),QPoint(400,350),":/jiang01.png");
    monster_list.push_back(mon);
    mon->move();
    update();

}
void Levelwindow::updatewindow()
{
    update();
}
void Levelwindow::setWay()
{
    Way* waypoi08=new Way(QPoint(750,150));
    theway_list.push_back(waypoi08);

    Way* waypoi07=new Way(QPoint(640,150));
    theway_list.push_back(waypoi07);
    waypoi07->setnextpoi(waypoi08);

    Way* waypoi06=new Way(QPoint(640,350));
    theway_list.push_back(waypoi06);
    waypoi06->setnextpoi(waypoi07);

    Way* waypoi05=new Way(QPoint(400,350));
    theway_list.push_back(waypoi05);
    waypoi05->setnextpoi(waypoi06);

    Way* waypoi04=new Way(QPoint(400,150));
    theway_list.push_back(waypoi04);
    waypoi04->setnextpoi(waypoi05);

    Way* waypoi03=new Way(QPoint(150,150));
    theway_list.push_back(waypoi03);
    waypoi03->setnextpoi(waypoi04);

    Way* waypoi02=new Way(QPoint(150,350));
    theway_list.push_back(waypoi02);
    waypoi02->setnextpoi(waypoi03);

    Way* waypoi01=new Way(QPoint(20,350));
    theway_list.push_back(waypoi01);
    waypoi01->setnextpoi(waypoi02);

}
