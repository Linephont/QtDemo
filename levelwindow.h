#ifndef LEVELWINDOW_H
#define LEVELWINDOW_H

#include <QMainWindow>
#include "tower.h"
class Levelwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Levelwindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void setatower();
    QString picpath;
private:
    QList<Tower*> tower_list;
signals:

};

#endif // LEVELWINDOW_H
