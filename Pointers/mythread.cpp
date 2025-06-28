#include "mythread.h"

#include <QDebug>

MyThread::MyThread(int id, QObject *parent)
    : id(id),  QThread{parent}
{
    // qDebug() << this->id << "MyThread Initiated!";

}
MyThread::MyThread(QObject *parent)
    : QThread{parent}
{
    // qDebug() << this->id << "MyThread Initiated!";

}

MyThread::~MyThread()
{
    // qDebug() << this->id << "MyThread deleted!";
}

void MyThread::setId(int id)
{
    this->id = id;
    // qDebug() << this->id << "MyThread Initiated!";

}
