#ifndef ARKANOID_H
#define ARKANOID_H

#include <QObject>

class GraphicsScene;
class QGraphicsView;

class Arkanoid : public QObject
{

public:
    Arkanoid(QGraphicsView *graphicsView,QObject *parent = nullptr);
    void starGame();
    void stopGame();
private:
    GraphicsScene *mScene;
};

#endif // ARKANOID_H
