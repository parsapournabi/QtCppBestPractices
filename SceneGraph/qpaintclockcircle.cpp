#include "clockcirclebackend.h"
#include <QPainter>
#include <QBrush>

#include "qpaintclockcircle.h"

DECLARE_BACKEND_PROPERTY(QPaintClockCircle)

QPaintClockCircle::QPaintClockCircle(QQuickItem *parent)
    : QQuickPaintedItem{parent},
    m_backend(new ClockCircleBackend(this))
{

}

void QPaintClockCircle::paint(QPainter *painter)
{
    // Object rendering
    QBrush brush(m_backend->backgroundColor());               // choose background color, ...
    QBrush brushActive(m_backend->borderActiveColor());       // active color rim, ...
    QBrush brushNonActive(m_backend->borderNonActiveColor()); // not active color of the rim

    painter->setPen(Qt::NoPen);                             // We remove the outline
    painter->setRenderHints(QPainter::Antialiasing, true);  // Turn on anti-aliasing

    painter->setBrush(brushNonActive);                          // Draw the lowest background in the form of a circle
    painter->drawEllipse(boundingRect().adjusted(1,1,-1,-1));   // with a fit for the current dimensions, which
    // will be defined in the QML layer.
    // This will not be the active background of the rim

    // Progress bar will be formed by drawing Pie graphics
    painter->setBrush(brushActive);                         // Draw the active background of the rim, depending on the angle of rotation
    painter->drawPie(boundingRect().adjusted(1,1,-1,-1),    // with a fit to the dimensions in the QML layer
                     90 * 16,         // Starting point
                     m_backend->angle() * 16);   // The angle of rotation to which you want to draw an object

    painter->setBrush(brush);       // The main background of the timer, overlapping which on top of the rest
    painter->drawEllipse(boundingRect().adjusted(10,10,-10,-10));   // will be formed a bezel (it's the same progress bar)
}
