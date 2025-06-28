#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qDebug() << "MainWindow ThreadId: " << QThread::currentThreadId();

    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug() << "Deleted MainWindow destructure!";
}

void MainWindow::onClicked() {
    emit signalDoWork();
}

void MainWindow::onSetText(QString text) { ui->label->setText(text); }

void MainWindow::onThreadStarted() {
    qDebug() << "Thread started!" << QThread::currentThreadId();
}

void MainWindow::onWorkerThreadStarted() {
    qDebug() << "WorkerThread started!" << QThread::currentThreadId();
}

void MainWindow::on_pushButton_2_clicked()
{
    emit signalStopClicked();
    qDebug() << "Stop Clicked!";
}


void MainWindow::on_pushButton_3_clicked()
{
    // this->deleteLater();
    emit destroyed();
}
