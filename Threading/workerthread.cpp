#include "workerthread.h"

#include <QMutex>

WorkerThread::WorkerThread(QObject *parent)
    : QThread{parent}
{
    qDebug() << "WorkerThread initiate";

}

WorkerThread::~WorkerThread() {
    qDebug() << "WorkerThread Deleted!";
}

void WorkerThread::setText(QLabel *label, QString text) {
    emit signalSetText(label, text);
}

void WorkerThread::run() {

    qDebug() << "WorkerThread running!" << QThread::currentThreadId();
    for (int i = 0; i < 100; ++i) {
        QMutex mutex;
        mutex.lock();
        if (Stop)
            break;
        // int div = i / 0;
        mutex.unlock();
        // label->setText(QString::fromStdString(std::to_string(i)));
        emit signalSetText(label, QString::number(i));
        QThread::msleep(100);
    }
}
