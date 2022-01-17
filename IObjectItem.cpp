#include "IObjectItem.h"

IObjectItem::IObjectItem(int x, int y, int w, int h, int vx, int vy, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    mx = x;
    my = y;
    mw = w;
    mh = h;
    mvx = vx;
    mvy = vy;
}

void IObjectItem::move()
{
    mx += mvx;
    my += mvy;
}

QRectF IObjectItem::boundingRect() const
{
    return QRectF(mx,my,mw,mh);
}
