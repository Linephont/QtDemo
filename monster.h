#ifndef MONSTER_H
#define MONSTER_H

#include <QObject>
#include <QPainter>
#include <QPixmap>
#include <QPoint>

class Monster : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint nowPoi READ getnowPoi WRITE setnowPoi)
public:
    explicit Monster(QObject *parent = nullptr);
    Monster(QPoint _startPoi,QPoint _endPoi,QString _filepath);
    void draw(QPainter* painter,int a,int b);
    void move();
    QPoint getnowPoi();
    void setnowPoi(QPoint newone);
private:
    QString filepath;
    QPixmap pix;
    QPoint startPoi,endPoi;
    QPoint nowPoi;
signals:

};

#endif // MONSTER_H
