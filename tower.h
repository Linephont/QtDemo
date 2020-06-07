#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QPoint>
#include <QPixmap>
class Tower : public QObject
{
    Q_OBJECT
public:
    explicit Tower(QObject *parent = nullptr);
    Tower(QPoint _poi,QString _filepath);
    void drawtower(QPainter* paint);
    QString filepath;
    QPoint poi;
    QPixmap pix;
signals:

};

#endif // TOWER_H
