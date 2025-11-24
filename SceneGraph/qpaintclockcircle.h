#ifndef QPAINTCLOCKCIRCLE_H
#define QPAINTCLOCKCIRCLE_H

#include <QQuickItem>
#include <QQuickPaintedItem>

#include "utils.h"

class ClockCircleBackend;
class QPaintClockCircle : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
    DEFINE_BACKEND_PROPERTY()
    /* A lot of code from the last lesson */
public:
    explicit QPaintClockCircle(QQuickItem *parent = nullptr);

    void paint(QPainter *painter) override; // Override the method in which our object will be rendered

    /* A lot of code from the last lesson */
private:
    QScopedPointer<ClockCircleBackend> m_backend;
};

#endif // QPAINTCLOCKCIRCLE_H
