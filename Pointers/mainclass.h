#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>
#include <QDebug>
#include <QPointer>

#include "mythread.h"
#include "child.h"


class MainClass : public QObject
{
    Q_OBJECT
public:
    explicit MainClass();

    explicit MainClass(int id, QObject *parent = nullptr);

    ~MainClass();

    void Func();

signals:

public:
    int id = -1;
    QSharedPointer<Child> child = nullptr;
    // MyThread *thread = nullptr;
    MyThread thread;
};

#endif // MAINCLASS_H
