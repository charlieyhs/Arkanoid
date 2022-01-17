#include "GraphicsScene.h"
#include "GlobalDefines.h"
#include "Util.h"
#include "ThreadTimer.h"
#include "BallItem.h"
#include "PlatformItem.h"

#include <QKeyEvent>


GraphicsScene::GraphicsScene(QObject *parent)
    : QGraphicsScene(0.0,0.0,XSIZE,YSIZE,parent)
{
    createObjects();
    configureObjects();
    connectObjects();
}

void GraphicsScene::startScene()
{
    mThreadTimer->start();
}

void GraphicsScene::stopScene()
{
    mThreadTimer->terminate();
}

void GraphicsScene::keyPressEvent(QKeyEvent *event)
{
    mPlatformItem->move(event->key());
}

void GraphicsScene::keyReleaseEvent(QKeyEvent *event)
{
    event->accept();
}

void GraphicsScene::createObjects()
{
     mThreadTimer = new ThreadTimer(MILISECONDS,this);
     mBallItem = new BallItem(XBALL,YBALL,WBALL,HBALL,VXBALL,VYBALL);
     mPlatformItem = new PlatformItem(XPLATFORM,YPLATFORM,WPLATFORM,HPLATFORM,VXPLATFORM,VYPLATFORM);
}

void GraphicsScene::configureObjects()
{
    addItem(mBallItem);
    addItem(mPlatformItem);
    addRect(0.0,0.0,XSIZE,YSIZE,QPen(QColor(Qt::red)));
}

void GraphicsScene::connectObjects()
{
    connect(mThreadTimer, &ThreadTimer::timeOut,this,&GraphicsScene::updateObjects);
}

void GraphicsScene::updateObjects()
{
    // la logica del juego
    mBallItem->move();
    if(mBallItem->collidesWithItem(mPlatformItem)){
        checkCollisions();
    }
    update();
}

void GraphicsScene::checkCollisions()
{
    int bvx = mBallItem->getvx();
    int bvy = mBallItem->getvy();
    const int pvx = mPlatformItem->getvx();
    const int pvy = mPlatformItem->getvy();

    if(bvx > 0 && bvy > 0 && pvx > 0 && pvy == 0){
        bvx = +Util::abs(bvx);
        bvy = -Util::abs(bvy);
    }else if(bvx < 0 && bvy > 0 && pvx > 0 && pvy == 0){
        bvx = -Util::abs(bvx);
        bvy = +Util::abs(bvy);
    }else if(bvx > 0 && bvy > 0 && pvx < 0 && pvy == 0){
        bvx = +Util::abs(bvx);
        bvy = -Util::abs(bvy);
    }else if(bvx < 0 && bvy > 0 && pvx < 0 && pvy ==0){
        bvx = -Util::abs(bvx);
        bvy = -Util::abs(bvy);
    }

    mBallItem->setvx(bvx);
    mBallItem->setvy(bvy);

}
