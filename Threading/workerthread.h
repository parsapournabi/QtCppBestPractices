#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QLabel>

class WorkerThread : public QThread
{
    Q_OBJECT
public:

    explicit WorkerThread(QObject *parent = nullptr);

    ~WorkerThread();

    void setText(QLabel *label, QString text);

signals:
    void signalSetText(QLabel *lablel, QString text);
protected:
    void run();

public:
    QLabel *label = nullptr;
    bool Stop = false;

};

#endif // WORKERTHREAD_H
