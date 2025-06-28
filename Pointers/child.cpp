#include "child.h"

Child::Child(QObject *parent)
    : QObject{parent}
{
    qDebug() << this << "Child Class Created ";
}

Child::~Child()
{
    qDebug() << this << "Child Class Deleted";
}
