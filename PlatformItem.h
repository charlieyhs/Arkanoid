#ifndef PLATFORMITEM_H
#define PLATFORMITEM_H

#include "IObjectItem.h"


class PlatformItem : public IObjectItem
{

public:
    PlatformItem(int x, int y, int w, int h, int vx, int vy, QGraphicsItem *parent = nullptr);
    void move(int key);
protected:

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget = nullptr) override;

};

#endif // PLATFORMITEM_H
