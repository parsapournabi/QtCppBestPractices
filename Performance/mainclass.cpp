#include "mainclass.h"
#include "gettersetterperf.h"

#include <QEventLoop>

MainClass::MainClass()
{
    GetterSetterPerf gsp;
    qDebug();
    int nan = 0;
    int copy = 1;
    int move = 2;
    int ref = 3;

    QString nanStr = "nan";
    QString copyStr = "copy";
    QString moveStr = "move";
    QString refStr = "ref";
    QString superStr = "super";

    qDebug() << "MAINCLASS Int NaN, Copy, Move, Ref: "  << &nan << &copy << &move << &ref;
    qDebug() << "MAINCLASS QString NaN, Copy, Move, Ref, Super: "  << &nanStr << &copyStr << &moveStr << &refStr << &superStr;
    qDebug();

    gsp.setNan(nan);
    gsp.setCopy(copy);
    gsp.setMove(std::move(move));
    gsp.setRef(ref);
    gsp.setSuperStr("m_superStr");

    gsp.setNanStr(nanStr);
    gsp.setCopyStr(copyStr);
    gsp.setMoveStr(std::move(moveStr));
    gsp.setRefStr(refStr);

    nan = gsp.nan();
    copy = gsp.copy();
    move = gsp.move();
    ref = gsp.ref();

    nanStr = gsp.nanStr();
    copyStr = gsp.copyStr();
    moveStr = gsp.moveStr();
    refStr = gsp.refStr();
    gsp.superStr(superStr);

    qDebug();
    qDebug() << "MAINCLASS AFTER ASSIGNMENT Int NaN, Copy, Move, Ref: "  << &nan << &copy << &move << &ref;
    qDebug() << "MAINCLASS AFTER ASSIGNMENT QString NaN, Copy, Move, Ref, Super: "  << &nanStr << &copyStr << &moveStr << &refStr << &superStr;

    int nanRes = gsp.nan();
    int copyRes = gsp.copy();
    int moveRes = gsp.move();
    int refRes = gsp.ref();

    QString nanStrRes = gsp.nanStr();
    QString copyStrRes = gsp.copyStr();
    QString moveStrRes = gsp.moveStr();
    QString refStrRes = gsp.refStr();
    QString superStrRes;
    gsp.superStr(superStrRes);

    qDebug();
    qDebug() << "MAINCLASS NEW RESULTS Int NaN, Copy, Move, Ref: "  << &nanRes << &copyRes << &moveRes << &refRes;
    qDebug() << "MAINCLASS NEW RESULTS QString NaN, Copy, Move, Ref, Super: "  << &nanStrRes << &copyStrRes << &moveStrRes << &refStrRes << &superStrRes;

    QVector<QString *> strLst/* = new QVector<QString *>()*/;
    strLst.resize(10e7);
    // memset(&strLst, 0, sizeof(QString) * 10e5);
    // QString mstr;
    // for (int i = 0; i < 10e7; ++i) {
    //     // gsp.superStr(mstr);
    //     QString mstr = gsp.refStr();
    //     strLst[i] = &mstr;
    // }
    QString mstr;
    gsp.superStr(mstr);
    std::fill(strLst.begin(), strLst.end(), &mstr);
    for (int j = 0; j < 10; ++j) {
        qDebug() << "Vector" << j << &strLst[j] ;
    }
    QEventLoop el;
    el.exec();

}


MainClass::~MainClass()
{

}

