#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QPushButton>
#include "myownwindow.h"
#include "mypushbutton.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    this->setFixedSize(800,600);
    ui->setupUi(this);
    Mypushbutton* startbutton=new Mypushbutton(":/start.png");
    startbutton->setParent(this);
    startbutton->move(this->width()*0.5-startbutton->width()*0.5,this->height()*0.7);
    Myownwindow* scene01=new Myownwindow;
    scene01->picpath=":/choosescene.jpg";
    connect(startbutton,&QPushButton::clicked,this,[=](){
        startbutton->jumpdown();
        startbutton->jumpup();
        QTimer::singleShot(350,this,[=](){
            this->hide();
            scene01->show();
        });


    });
    connect(scene01,&Myownwindow::choosesceneback,this,[=](){
        scene01->hide();
        this->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{

     QPainter paint(this);
     QPixmap pix;
     pix.load(":/background.png");
     paint.drawPixmap(0,0,this->width(),this->height(),pix);




}
