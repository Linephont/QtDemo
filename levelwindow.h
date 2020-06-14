#ifndef LEVELWINDOW_H
#define LEVELWINDOW_H

#include <QMainWindow>
#include "tower.h"
#include <QList>
#include "mypushbutton.h"
#include "monster.h"
#include "way.h"
class Levelwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Levelwindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void setatower();
    void startmonster();
    QString picpath;
    void updatewindow();
    void setWay();
private:
    QList<Tower*> tower_list;
    QList<Monster*> monster_list;
    QList<Way*>theway_list;
signals:

};

#endif // LEVELWINDOW_H
