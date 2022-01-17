#include "ThreadTimer.h"

ThreadTimer::ThreadTimer(int miliseconds, QObject *parent)
    : QThread(parent)
{
    mMiliseconds = miliseconds;
}

void ThreadTimer::run()
{
    while(true){
        emit timeOut();
        QThread::msleep(mMiliseconds);
    }
}
