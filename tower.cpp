#include "tower.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>
Tower::Tower(QObject *parent) : QObject(parent)
{

}
Tower::Tower(QPoint _poi,QString _filepath):pix(_filepath)
{
    poi=_poi;
}
void Tower::drawtower(QPainter *paint)
{
    paint->drawPixmap(poi,pix);
}
