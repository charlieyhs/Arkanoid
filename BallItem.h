#ifndef BALLITEM_H
#define BALLITEM_H

#include "IObjectItem.h"

class BallItem : public IObjectItem
{

public:
    BallItem(int c, int y, int w, int h, int vx, int vy, QGraphicsItem *parent = nullptr);
    void move() override;
protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget = nullptr) override;

};

#endif // BALLITEM_H
