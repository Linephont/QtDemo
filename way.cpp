#include "way.h"
#include <QPoint>
Way::Way(QObject *parent) : QObject(parent)
{

}
Way::Way(QPoint _poi)
{
    now=_poi;
}
void Way::setnextpoi(Way *_next)
{
    next=_next;
}
QPoint Way::shownowpoi()
{
    return now;
}
