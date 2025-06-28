#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

#include "workerthread.h"
#include "worker.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void signalStopClicked();

    void signalDoWork();

public slots:
    void onClicked();
    void onSetText(QString text);

    void onThreadStarted();

    void onWorkerThreadStarted();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

public:
    Ui::MainWindow *ui;

    QThread *thread = nullptr;
    WorkerThread *workerThread = nullptr;
    Worker *worker = nullptr;
};
#endif // MAINWINDOW_H
