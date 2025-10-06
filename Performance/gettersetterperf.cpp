#include "gettersetterperf.h"

#include <QDebug>


GetterSetterPerf::GetterSetterPerf(QObject *parent) :
    QObject{parent}
{
    qDebug() << "GetterSetterPerf Initialized" << this;
    qDebug() << "Int NaN, Copy, Move, Ref: "  << &m_nan << &m_copy << &m_move << &m_ref;
    qDebug() << "QString NaN, Copy, Move, Ref: "  << &m_nanStr << &m_copyStr << &m_moveStr << &m_refStr;
}

GetterSetterPerf::~GetterSetterPerf()
{
    qDebug() << "GetterSetterPerf Destructure" << this;
}

int GetterSetterPerf::nan() const { return m_nan; }
void GetterSetterPerf::setNan(int data) {
    qDebug() << "Int setNan NaN, data: " << &m_nan << &data;
    m_nan = data;
}

int GetterSetterPerf::copy() const { return m_copy; }
void GetterSetterPerf::setCopy(int data) {
    qDebug() << "Int setCopy Copy, data: " << &m_copy << &data;
    m_copy = data;
}

int GetterSetterPerf::move() const { return m_move; }
void GetterSetterPerf::setMove(int &&data) {
    qDebug() << "Int setMove Move, data: " << &m_move << &data;
    m_move = std::move(data);
}

const int &GetterSetterPerf::ref() const { return m_ref; }
void GetterSetterPerf::setRef(int &data) {
    qDebug() << "Int setRef Ref, data: " << &m_ref<< &data;
    m_ref = data;
}

QString GetterSetterPerf::nanStr() const { return m_nanStr; }
void GetterSetterPerf::setNanStr(QString data) {
    qDebug() << "QString setNan Nan, data: " << &m_nanStr << &data;
    m_nanStr = data;
}

QString GetterSetterPerf::copyStr() const { return m_copyStr; }
void GetterSetterPerf::setCopyStr(QString data) {
    qDebug() << "QString setCopy Copy, data: " << &m_copyStr << &data;
    m_copyStr = data;
}

QString GetterSetterPerf::moveStr() const { return m_moveStr; }
void GetterSetterPerf::setMoveStr(const QString &&data) {
    qDebug() << "QString setMove Move, data: " << &m_moveStr << &data;
    m_moveStr = std::move(data);
}

const QString &GetterSetterPerf::refStr() const { return m_refStr; }
void GetterSetterPerf::setRefStr(const QString &data) {
    qDebug() << "QString setRef Ref, data: " << &m_refStr << &data;
    m_refStr = data;
}

void GetterSetterPerf::superStr(QString &data) const { data = m_superStr; }
void GetterSetterPerf::setSuperStr(const QString &data) { m_superStr = data; }
