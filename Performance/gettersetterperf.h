#ifndef GETTERSETTERPERF_H
#define GETTERSETTERPERF_H

#include <QObject>

class GetterSetterPerf : public QObject
{
    Q_OBJECT
public:
    explicit GetterSetterPerf(QObject *parent = nullptr);

signals:

private:

};

#endif // GETTERSETTERPERF_H
