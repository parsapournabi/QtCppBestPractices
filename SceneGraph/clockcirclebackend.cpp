#include "clockcirclebackend.h"

#include <QTimer>
#include <QQuickPaintedItem>

ClockCircleBackend::ClockCircleBackend(QQuickItem *parent) :
    QQuickItem{parent},
    m_backgroundColor(Qt::white),
    m_borderActiveColor(Qt::blue),
    m_borderNonActiveColor(Qt::gray),
    m_angle(0),
    m_circleTime(QTime(0,0,0,0))
{
    internalTimer = new QTimer(this);   // Initialize timer
    /* Also connected to the timer signal from the lambda function
     * Structure lambda functions [object] (arguments) {body}
     * */
    connect(internalTimer, &QTimer::timeout, [=](){
        setAngle(angle() - 0.3);                    // rotation is determined in degrees.
        setCircleTime(circleTime().addMSecs(50));   // Adding to the current time of 50 milliseconds
        emit updated();                                   // redraws the object
    });
    makeConnection();
}

void ClockCircleBackend::clear()
{
    setCircleTime(QTime(0,0,0,0));  // Clean up time
    setAngle(0);                    // Expose turn to zero
    emit updated();                       // update object
    emit cleared();                 // Emits a clear signal
}

void ClockCircleBackend::start()
{
    internalTimer->start(50);       // Start the timer in increments of 50 ms
}

void ClockCircleBackend::stop()
{
    internalTimer->stop();          // stops the timer
}

QString ClockCircleBackend::name() const
{
    return m_name;
}

QColor ClockCircleBackend::backgroundColor() const
{
    return m_backgroundColor;
}

QColor ClockCircleBackend::borderActiveColor() const
{
    return m_borderActiveColor;
}

QColor ClockCircleBackend::borderNonActiveColor() const
{
    return m_borderNonActiveColor;
}

qreal ClockCircleBackend::angle() const
{
    return m_angle;
}

QTime ClockCircleBackend::circleTime() const
{
    return m_circleTime;
}

bool ClockCircleBackend::makeConnection() const
{
    if (!parent()) return false;
    if (m_parentSigSlotConnection) {
        qWarning() << "[WARNING]: " << __FUNCTION__ << "has already signal/slot connection!";
        return false;
    }
    if (parent()->inherits("QQuickPaintedItem")) {
        qDebug() << "[DEBUG]: " << __PRETTY_FUNCTION__ << "Parent is base of QQuickPaintedItem" << parent() << this;
        connect(this, &ClockCircleBackend::updated, parent(), [=]() { qobject_cast<QQuickPaintedItem *>(parent())->update(); });
    }
    else if (parent()->isQuickItemType()) {
        qDebug() << "[DEBUG]: " << __PRETTY_FUNCTION__ << "Parent is base of QQuickItem" << parent() << this;
        connect(this, &ClockCircleBackend::updated, static_cast<QQuickItem *>(parent()), &QQuickItem::update);
    }
    else {
        qCritical() << "[ERROR]: " << __PRETTY_FUNCTION__ << "Parent is None of the QQuickItem or QQuickPaintedItem" << parent() << this;
        return false;
    }
    return true;
}

void ClockCircleBackend::setName(const QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(name);
}

void ClockCircleBackend::setBackgroundColor(const QColor backgroundColor)
{
    if (m_backgroundColor == backgroundColor)
        return;

    m_backgroundColor = backgroundColor;
    emit backgroundColorChanged(backgroundColor);
}

void ClockCircleBackend::setBorderActiveColor(const QColor borderActiveColor)
{
    if (m_borderActiveColor == borderActiveColor)
        return;

    m_borderActiveColor = borderActiveColor;
    emit borderActiveColorChanged(borderActiveColor);
}

void ClockCircleBackend::setBorderNonActiveColor(const QColor borderNonActiveColor)
{
    if (m_borderNonActiveColor == borderNonActiveColor)
        return;

    m_borderNonActiveColor = borderNonActiveColor;
    emit borderNonActiveColorChanged(borderNonActiveColor);
}

void ClockCircleBackend::setAngle(const qreal angle)
{
    if (m_angle == angle)
        return;

    m_angle = angle;

    /* This addition is made to reset the rotation when the timer 60 seconds
     * */
    if(m_angle <= -360) m_angle = 0;
    emit angleChanged(m_angle);
}

void ClockCircleBackend::setCircleTime(const QTime circleTime)
{
    if (m_circleTime == circleTime)
        return;

    m_circleTime = circleTime;
    emit circleTimeChanged(circleTime);
}
