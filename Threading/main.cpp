#include "mainwindow.h"

#include <QApplication>
#include <QException>
#include <worker.h>
#include <QMutex>
#include <QMetaObject>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // w.setWindowFlags(Qt::FramelessWindowHint);

    QThread thread(&w);
    Worker worker;
    worker.moveToThread(&thread);
    // w.moveToThread(&thread1);


    // QObject::connect(&worker, &Worker::destroyed, &thread, &QThread::quit);
    QObject::connect(&worker, &Worker::destroyed, &worker, [=]() { qDebug() << "DEATH Worker;"; });

    QObject::connect(&thread, &QThread::started, &w, &MainWindow::onThreadStarted);
    QObject::connect(&thread, &QThread::finished, &thread, [=]() {qDebug() << "Thread finished!"; });
    // QObject::connect(&thread, &QThread::finished, &worker, &Worker::deleteLater);
    QObject::connect(&thread, &QThread::destroyed, &thread, [=]() { qDebug() << "DEATH THread;"; });
    QObject::connect(&thread, &QThread::destroyed, &w, &MainWindow::deleteLater);
    // QObject::connect(&thread, &QThread::destroyed, &w, [=]() { exit(EXIT_SUCCESS); });

    // QObject::connect(&w, &MainWindow::destroyed, &thread, &QThread::quit);
    // QObject::connect(&w, &MainWindow::destroyed, &thread, &QThread::deleteLater);
    // QObject::connect(&w, &MainWindow::destroyed, &worker, &Worker::deleteLater);
    QObject::connect(&w, &MainWindow::destroyed, &thread, &QThread::quit, Qt::DirectConnection);
    QObject::connect(&w, &MainWindow::destroyed, &w, [=]() { qDebug() << "DEATH;"; });

    QObject::connect(&worker, &Worker::signalSetText, &w, &MainWindow::onSetText);
    QObject::connect(&w, &MainWindow::signalDoWork, &worker, &Worker::doWorkHandler);
    QObject::connect(&w, &MainWindow::signalStopClicked, &worker, &Worker::onStop);
    // QObject::connect(&w, &MainWindow::signalStopClicked, &thread, [&] () { QMutex mutex; mutex.lock(); worker.m_stop = true; mutex.unlock(); });
    // QObject::connect(&w, &MainWindow::signalDoWork, &w, [=] () {
    //     QMetaObject::invokeMethod(&worker, &Worker::doWorkHandler); });

    thread.start();
    // thread.quit();


    w.show();

    return a.exec();
}
