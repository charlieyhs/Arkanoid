#include "BallItem.h"
#include "GlobalDefines.h"
#include <QPainter>
BallItem::BallItem(int x, int y, int w, int h, int vx, int vy, QGraphicsItem *parent)
    : IObjectItem(x,y,w,h,vx,vy,parent)
{

}

void BallItem::move()
{
    if(mx < 0 || mx > (XSIZE - WBALL)){
        mvx = -mvx;
    }
    if(my < 0 || my > (YSIZE-HBALL)){
        mvy = -mvy;
    }
    IObjectItem::move();
}

void BallItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawEllipse(mx,my,mw,mh);

}

