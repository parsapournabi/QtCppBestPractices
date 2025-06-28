#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QLabel>
#include <QException>
#include <QEventLoop>
#include <QThread>


class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

    ~Worker();


signals:
    void signalSetText(QString text);

public slots:
    void doWorkHandler();
    void onStop();
private:
    void doWork();

public:
    bool m_stop = false;

private:
    QEventLoop eLoop;
    QThread workerThread;

};

#endif // WORKER_H
