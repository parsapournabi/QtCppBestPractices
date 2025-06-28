#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>
#include <QDebug>
#include <QPointer>


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

};

#endif // MAINCLASS_H
