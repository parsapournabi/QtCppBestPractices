#ifndef GETTERSETTERPERF_H
#define GETTERSETTERPERF_H

#include <QObject>

class GetterSetterPerf : public QObject
{
    Q_OBJECT
public:
    explicit GetterSetterPerf(QObject *parent = nullptr);
    ~GetterSetterPerf();

    int nan() const;
    void setNan(int data);

    int copy() const;
    void setCopy(int data);

    int move() const;
    void setMove(int &&data);

    const int &ref() const;
    void setRef(int &data);

    QString nanStr() const;
    void setNanStr(QString data);

    QString copyStr() const;
    void setCopyStr(QString data);

    QString moveStr() const;
    void setMoveStr(const QString &&data);

    const QString &refStr() const;
    void setRefStr(const QString &data);

    void superStr(QString &data) const;
    void setSuperStr(const QString &data);

signals:

private:
    int m_nan;
    int m_copy = -1;
    int m_move = -1;
    int m_ref = -1;

    QString m_nanStr;
    QString m_copyStr = "";
    QString m_moveStr = "";
    QString m_refStr = "";
    QString m_superStr = "";

};

#endif // GETTERSETTERPERF_H
