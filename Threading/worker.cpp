#include "worker.h"

#include <QThread>
#include <QMutex>
#include <QDebug>


Worker::Worker(QObject *parent)
    : QObject{parent}
{

    qDebug() << "Worker Class initiated" << QThread::currentThreadId();
    connect(&workerThread, &QThread::started, this, [=] () { QMetaObject::invokeMethod(this, [=] () {doWork(); }); });
    connect(&workerThread, &QThread::finished, this, [=] () { qDebug() << "Worker workerThread finished!"; });


}

Worker::~Worker() {
    qDebug() << "Worker Class deleted!" << QThread::currentThreadId();
}

void Worker::doWork() {
    qDebug() << "Worker ThreadId: " << QThread::currentThreadId();
    m_stop = false;
    for (int i = 0; i < 10; ++i) {
        QMutex mutex;
        mutex.lock();
        if (m_stop)
            eLoop.exec();
            // QThread: :msleep(1);
        mutex.unlock();
        emit signalSetText(QString::number(i));
        QThread::msleep(100);

    }
    workerThread.quit();

}

void Worker::doWorkHandler() {
    if (eLoop.isRunning()) {
        m_stop = false;
        // eLoop.quit();
    }
    else
        workerThread.start();
        // doWork();
}

void Worker::onStop() {
    m_stop = true;
    qDebug() << "onStop clicked!";
}

