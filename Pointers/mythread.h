#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    explicit MyThread(int id, QObject *parent = nullptr);
    ~MyThread();
    void setId(int id);

public:
    int id = -1;
};

#endif // MYTHREAD_H
