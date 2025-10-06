#ifndef DERRIVED_H
#define DERRIVED_H

#include "Base.h"

class ME : public ItemBase {
    Q_OBJECT
public:
    ME() {}
    ME(int val) : m_val(val) {}
    ME(const ME &other) {
        // qDebug() << "on Copy: " << this->m_val << other.m_val;
        if (this == &other)
            return;
        this->m_val = other.m_val;

    }
    ME & operator=(const ME& other) {
        qDebug() << "on operator" << this->m_val << other.m_val;
        if (this == &other)
            qCritical() << "ERROR: on operator= ME class other == this" << this << &other;
        this->m_val = other.m_val;

    }
    int value() const { return m_val; }
private:
    int m_val = -1;
};

class Derrrived : public Base<ME>  {
public:

};

#endif // DERRIVED_H
