#include "Arkanoid.h"
#include "GraphicsScene.h"

#include <QGraphicsView>

Arkanoid::Arkanoid(QGraphicsView *graphicsView, QObject *parent)
    : QObject(parent)
{
    mScene = new GraphicsScene(this);
    graphicsView->setScene(mScene);

}

void Arkanoid::starGame()
{
    mScene->startScene();
}

void Arkanoid::stopGame()
{
    mScene->stopScene();
}
