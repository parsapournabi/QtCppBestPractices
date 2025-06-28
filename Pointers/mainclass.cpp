#include "mainclass.h"
#include <QPointer>
#include <iostream>

MainClass::MainClass()
{
    // qDebug() << this->id << "MainClass Initiated!" << this << QThread::currentThreadId();
    thread.setId(this->id);
    // this->moveToThread(thread);
    // QObject::connect(&thread, &MyThread::started, this, [&]() { std::cout << id << "Thread Started!" << this;}, Qt::DirectConnection);
    // QObject::connect(&thread, &MyThread::finished, this, [=]() { qDebug() << id << "Thread Finished!" << this;});
    // thread->start();
    // child = QSharedPointer<Child>::create();
    Func();
}

MainClass::MainClass(int id, QObject *parent)
    : id(id), QObject{parent}
{
    // child = QSharedPointer<Child>::create();

    thread.setId(this->id);
    // this->moveToThread(thread);
    // QObject::connect(&thread, &MyThread::started, this, [&]() { qDebug() << this->id << "Thread Started!" << this;}, Qt::DirectConnection);
    // QObject::connect(&thread, &MyThread::finished, this, [=]() { qDebug() << this->id << "Thread Finished!" << this;}, Qt::DirectConnection);
    // thread->start();
    Func();
    // qDebug() << this->id << "MainClass initiated!" << this << QThread::currentThreadId();


}

MainClass::~MainClass()
{
    // thread.quit();
    // thread.wait();
    // qDebug() << thread << thread->isRunning() << thread->currentThreadId();
    // thread->deleteLater();

    // thread->wait();
    // qDebug() << this->id << "MainClass Deleted!" << QThread::currentThreadId();
}

void MainClass::Func()
{
    // thread.start();
    // thread.deleteLater();
}
