#include "clockcirclebackend.h"

#include <QSGFlatColorMaterial>
#include <QOpenGLFunctions>
#include "qsgclockcircle.h"

DECLARE_BACKEND_PROPERTY(QSGClockCircle)

QSGClockCircle::QSGClockCircle(QQuickItem *parent)
    : QQuickItem{parent},
    m_backend(new ClockCircleBackend(this))
{
    setFlag(ItemHasContents, true);
}

#include <QtQuick>
#include <QtQuick/QSGGeometryNode>
#include <QtQuick/QSGFlatColorMaterial>
#include <QtMath>

QSGNode* QSGClockCircle::updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData*)
{
    const qreal w = width();
    const qreal h = height();
    const QPointF center(w/2, h/2);
    const qreal radiusOuter = qMin(w,h)/2 - 1;
    const qreal radiusInner = radiusOuter - 10;
    const int SEGMENTS = 64; // تعداد vertex برای smooth دایره و pie

    QSGNode* rootNode = oldNode;

    if (!rootNode) {
        rootNode = new QSGNode();

        // ---------- Non-active rim ----------
        QSGGeometry* geomNonActive = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), SEGMENTS + 2);
        geomNonActive->setDrawingMode(GL_TRIANGLE_FAN);

        auto* vertsNA = geomNonActive->vertexDataAsPoint2D();
        vertsNA[0].set(center.x(), center.y());
        for (int i = 0; i <= SEGMENTS; ++i) {
            double rad = qDegreesToRadians(i * 360.0 / SEGMENTS);
            vertsNA[i+1].set(std::cos(rad)*radiusOuter + center.x(), std::sin(rad)*radiusOuter + center.y());
        }

        QSGFlatColorMaterial* matNA = new QSGFlatColorMaterial();
        matNA->setColor(m_backend->borderNonActiveColor());

        QSGGeometryNode* nodeNA = new QSGGeometryNode();
        nodeNA->setGeometry(geomNonActive);
        nodeNA->setMaterial(matNA);
        nodeNA->setFlags(QSGNode::OwnsGeometry | QSGNode::OwnsMaterial);

        rootNode->appendChildNode(nodeNA);

        // ---------- Inner background ----------
        QSGGeometry* geomBG = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), SEGMENTS + 2);
        geomBG->setDrawingMode(GL_TRIANGLE_FAN);

        auto* vertsBG = geomBG->vertexDataAsPoint2D();
        vertsBG[0].set(center.x(), center.y());
        for (int i = 0; i <= SEGMENTS; ++i) {
            double rad = qDegreesToRadians(i * 360.0 / SEGMENTS);
            vertsBG[i+1].set(std::cos(rad)*radiusInner + center.x(), std::sin(rad)*radiusInner + center.y());
        }

        QSGFlatColorMaterial* matBG = new QSGFlatColorMaterial();
        matBG->setColor(m_backend->backgroundColor());

        QSGGeometryNode* nodeBG = new QSGGeometryNode();
        nodeBG->setGeometry(geomBG);
        nodeBG->setMaterial(matBG);
        nodeBG->setFlags(QSGNode::OwnsGeometry | QSGNode::OwnsMaterial);

        nodeNA->appendChildNode(nodeBG);

        // ---------- Active rim ----------
        QSGGeometry* geomActive = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), SEGMENTS + 2);
        geomActive->setDrawingMode(GL_TRIANGLE_FAN);
        auto* vertsActive = geomActive->vertexDataAsPoint2D();
        for (int i = 0; i <= SEGMENTS + 1; ++i)
            vertsActive[i].set(center.x(), center.y()); // initialize to center

        QSGFlatColorMaterial* matActive = new QSGFlatColorMaterial();
        matActive->setColor(m_backend->borderActiveColor());

        m_borderActiveNode = new QSGGeometryNode();
        m_borderActiveNode->setGeometry(geomActive);
        m_borderActiveNode->setMaterial(matActive);
        m_borderActiveNode->setFlags(QSGNode::OwnsGeometry | QSGNode::OwnsMaterial);

        nodeNA->appendChildNode(m_borderActiveNode);
    }

    // ---------- Update Active Rim ----------
    if (m_borderActiveNode) {
        int angle = static_cast<int>(m_backend->angle());
        if (angle < 2) angle = 2;
        if (angle > 360) angle = 360;

        auto* verts = m_borderActiveNode->geometry()->vertexDataAsPoint2D();
        verts[0].set(center.x(), center.y());

        // vertex های Pie
        for (int i = 0; i <= SEGMENTS; ++i) {
            double t = qMin(1.0, double(i)/SEGMENTS * angle/360.0);
            double rad = qDegreesToRadians(90 + t * angle);
            verts[i+1].set(std::cos(rad)*radiusOuter + center.x(), std::sin(rad)*radiusOuter + center.y());
        }

        // vertex های باقی مانده روی مرکز
        for (int i = angle*SEGMENTS/360 + 2; i <= SEGMENTS + 1; ++i)
            verts[i].set(center.x(), center.y());

        m_borderActiveNode->markDirty(QSGNode::DirtyGeometry);
    }

    return rootNode;
}
