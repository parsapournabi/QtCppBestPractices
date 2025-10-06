#include <QApplication>
#include "Derrived.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Derrrived d;

    ME ib;
    ME ib1;
    ME ib2(8);
    ME ib3(99);
    QList<ME> mes = {ib1, ib2, ib3};
    d.insertItems(mes);
    {
        QList<ME> mm;
        for (int i =0; i < 1'000'000; ++i) {
            mm.append(ME(i));
        }
        d.insertItems(mm);
    }
    qDebug() << "IB: " << ib.row() << ib.id() << &ib;
    qDebug() << "insert result: " << d.insertItem(&ib, 10);
    qDebug() << "IB: " << ib.row() << ib.id() << &ib;
    // qDebug() << "Item: " << d.item(0)->row() << d.item(0)->id() << d.item(0);

    // d.item(0)->setId(11);
    qDebug() << "IB: " << ib.row() << ib.id() << &ib;
    qDebug() << "Item: " << d.item(0)->row() << d.item(0)->id() << d.item(0);

    d.item(0)->setId(85);
    for (int i = 0; i < d.count(); ++i) {
        // qDebug() << "At Item: " << i << d.item(i)->id() << d.item(i)->row() << d.item(i)->value();
    }
    qDebug() << "Count: " << d.count();
    qDebug() << "Clearing...";
    d.clear();
    qDebug() << "Count: " << d.count();
    for (int i = 0; i < d.count(); ++i) {
        // qDebug() << "At Item: " << i << d.item(i)->id() << d.item(i)->row() << d.item(i)->value();
    }


    return a.exec();
}
