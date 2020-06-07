#include "myownwindow.h"
#include <QPainter>
#include "mypushbutton.h"
#include "levelwindow.h"
#include <QTimer>
Myownwindow::Myownwindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(800,600);
    Mypushbutton* backbutton=new Mypushbutton(":/back.png");
    backbutton->setParent(this);
    backbutton->move(700,500);
    connect(backbutton,&Mypushbutton::clicked,this,[=](){
        emit choosesceneback();
    });
    Mypushbutton* chooselevel01=new Mypushbutton(":/level01btn.png");
    chooselevel01->setParent(this);
    chooselevel01->move(100,80);
    Levelwindow* level01scene=new Levelwindow;
    level01scene->picpath=":/level01background.png";
    connect(chooselevel01,&QPushButton::clicked,this,[=](){
        chooselevel01->jumpdown();
        chooselevel01->jumpup();
        QTimer::singleShot(350,this,[=](){
            this->hide();
            level01scene->show();
        });


    });
//    Mypushbutton *maketower=new Mypushbutton(":/start.png");
//    maketower->setParent(this);
//    maketower->move(300,300);
//    connect(maketower,&Mypushbutton::clicked,this,&Myownwindow::setatower);
}
void Myownwindow::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    QPixmap pix;
    pix.load(picpath);
    paint.drawPixmap(0,0,this->width(),this->height(),pix);
//    foreach(Tower* onetower,tower_list)
//        onetower->drawtower(&paint);
}
//void Myownwindow::setatower(){
//    Tower* tower01=new Tower(QPoint(250,250),":/yasina.png");
//    tower_list.push_back(tower01);
//    update();

//}
