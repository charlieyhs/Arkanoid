#include "PlatformItem.h"
#include "GlobalDefines.h"
#include "Util.h"
#include <QPainter>

PlatformItem::PlatformItem(int x, int y, int w, int h, int vx, int vy, QGraphicsItem *parent)
    : IObjectItem(x,y,w,h,vx,vy,parent)
{

}

void PlatformItem::move(int key)
{
    if(mx > 0 && key == Qt::Key_Left){
        mvx = -Util::abs(mvx);
        IObjectItem::move();
    }else if(mx < (XSIZE - WPLATFORM) && key == Qt::Key_Right){
        mvx = +Util::abs(mvx);
        IObjectItem::move();
    }
}

void PlatformItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(mx,my,mw,mh);
    painter->fillRect(mx,my,mw,mh,Qt::blue);

}


