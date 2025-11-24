#ifndef QSGCLOCKCIRCLE_H
#define QSGCLOCKCIRCLE_H

#include <QSGGeometryNode>
#include <QQuickItem>

#include "clockcirclebackend.h"

#include "utils.h"

class ClockCircleBackend;
class QSGClockCircle : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT
    DEFINE_BACKEND_PROPERTY()
    /* A lot of code from the last lesson */

public:
    explicit QSGClockCircle(QQuickItem *parent = 0);

protected:
    virtual QSGNode* updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData* updatePaintNodeData) override;

private:
    /* A lot of code from the last lesson */

    QSGGeometryNode* m_borderActiveNode;

    QScopedPointer<ClockCircleBackend> m_backend;
};

#endif // QSGCLOCKCIRCLE_H
