#ifndef MYOWNWINDOW_H
#define MYOWNWINDOW_H

#include <QMainWindow>
#include "tower.h"
class Myownwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Myownwindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    QString picpath;
    void setatower();
private:
    QList<Tower*> tower_list;
signals:
    void choosesceneback();
};

#endif // MYOWNWINDOW_H
