#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
class ThreadTimer;
class BallItem;
class PlatformItem;
class GraphicsScene : public QGraphicsScene
{

public:
    GraphicsScene(QObject *parent = nullptr);
    void startScene();
    void stopScene();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
private:
    void createObjects();
    void configureObjects();
    void connectObjects();
    void updateObjects();
    void checkCollisions();

    ThreadTimer *mThreadTimer;
    BallItem *mBallItem;
    PlatformItem *mPlatformItem;
};

#endif // GRAPHICSSCENE_H
