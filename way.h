#ifndef WAY_H
#define WAY_H

#include <QObject>
#include <QPoint>
#include <QPainter>
class Way : public QObject
{
    Q_OBJECT
public:
    explicit Way(QObject *parent = nullptr);
    Way(QPoint _poi);
    void setnextpoi(Way* _next);
    QPoint shownowpoi();
    void draw(QPainter& paint);
private:
    QPoint now;
    Way* next;

signals:

};

#endif // WAY_H
