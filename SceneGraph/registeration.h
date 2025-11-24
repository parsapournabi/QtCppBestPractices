#ifndef REGISTERATION_H
#define REGISTERATION_H

#include "qpaintclockcircle.h"
#include "qsgclockcircle.h"

#define QT_QML_REGISTER(type, name) \
qmlRegisterType<type>(name, 1, 0, #type);

static void registerTypes()
{
    QT_QML_REGISTER(ClockCircleBackend, "ClockCircle")
    QT_QML_REGISTER(QSGClockCircle, "ClockCircle")
    QT_QML_REGISTER(QPaintClockCircle, "ClockCircle")
}

Q_COREAPP_STARTUP_FUNCTION(registerTypes)

#endif // REGISTERATION_H
