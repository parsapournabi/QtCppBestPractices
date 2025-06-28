#include <QCoreApplication>
#include <QPointer>
#include <QSharedPointer>
#include <QScopedPointer>
#include <QSharedDataPointer>

#include "mainclass.h"

/*** TODO: memcpy ***/
QList<const MainClass *> print(QList<MainClass *> &mc) {
    QList<const MainClass *> mc1;
    qDebug() << "on print address: " <<  &mc << mc.data() << &mc1 << mc1.data();
    for (auto &m : mc) {
        mc1.append(new MainClass(m->id, m));
    }
    qDebug() << "2 on print address: " <<  &mc << mc.data() << &mc1 << mc1.data();
    return mc1;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Stack (NoN-Pointer)
    MainClass mainC0(0);
    {
        MainClass mainC1(1);
    }

    {
        // Heap Dangerous
        MainClass *mainC2 = nullptr;
        {
            mainC2 = new MainClass(2);
        }
        // QPointer
        QPointer<MainClass> mainC3 = new MainClass(3);
        // Also Normal pointer C++
        MainClass *mainC4 = new MainClass(4, mainC2);
        delete mainC2;
        // delete mainC4;
        delete mainC3;
        // mainC2->deleteLater();

        // QSocpedPointer
        QScopedPointer<MainClass> mainC5(new MainClass(5));

        // QSharedPointer
        QSharedPointer<MainClass> mainC6(new MainClass(6));
        QSharedPointer<MainClass> mainC7 = QSharedPointer<MainClass>::create();

    }

    /** Memory address algorithm on SharedPointers **/
    qDebug() << "=============================================================================================";
    QList<MainClass *> mainCList;
    QList<const MainClass *> mainCList2;
    for (int i = 0; i < 10000; ++i) {
#define NORMAL_POINTER
// #define QNORMAL_POINTER
// #define QSCOPED_POINTER

#ifdef NORMAL_POINTER
        // bool *mainC = new bool(i);
        MainClass *mainC = new MainClass(i);
        mainCList.append(mainC);
        // qDebug() << "First MainClass" << i << " address: " << mainC << sizeof(*mainC);
        // qDebug() << "mainC size: " << sizeof(*mainC);
        // mainC->deleteLater();
        // qDebug() << "mainC SIZE: " << sizeof(*mainC);
        // delete mainC;
// MainClass *secMainC = new MainClass(i);
        // qDebug() << "Second MainClass" << i << " address: " << mainC;
        // delete secMainC;
        // qDebug();
#elifdef QNORMAL_POINTER
        QPointer<MainClass> mainC = new MainClass(i);
        // qDebug() << "mainC size: " << sizeof(mainC);
        // mainC->deleteLater();
        // qDebug() << "mainC SIZE: " << sizeof(mainC);
        // delete mainC;
        // qDebug() << "First MainClass" << i << " address: " << mainC;
        // delete mainC;
        // MainClass *secMainC = new MainClass(i);
        // qDebug() << "Second MainClass" << i << " address: " << mainC;
        // delete secMainC;
        // qDebug();

#elifdef QSCOPED_POINTER
        QScopedPointer<MainClass> mainC5(new MainClass(i));

#else
        QSharedPointer<MainClass> mainC = QSharedPointer<MainClass>::create(i);
        // qDebug() << "First MainClass" << i << " address: " << mainC;
        // delete mainC;
        // MainClass *secMainC = new MainClass(i);
        // qDebug() << "Second MainClass" << i << " address: " << mainC;
        // delete secMainC;
        // qDebug();

#endif
    }
    // mainCList.at(0)->id = 500;
    // mainCList.clear();
    qDebug() << "Before print address: " << &mainCList << mainCList.data() << &mainCList2 << mainCList2.data();
    // qDebug() << "Before print COPY address: " << &mainCList2 << mainCList2.data();
    mainCList2 = print(mainCList);
    qDebug() << "After print COPY address: " << &mainCList2 << mainCList2.data();
    // mainCList2[10]->id = 20;
    qDebug() << "DONE" << mainCList.size() << mainCList.empty() << mainCList[10]->id << mainCList2[10]->id;




    return a.exec();
}
