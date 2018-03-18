#include "scene_view.h"

SceneView::SceneView(QWidget* parent)
    : QGraphicsView{ parent }
{
    setMouseTracking(true);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void SceneView::resetView()
{
    resetMatrix();
    centerOn(sceneRect().center());
}

void SceneView::wheelEvent(QWheelEvent* ev)
{
    const int numDegrees = ev->delta() / 8;
    const int numSteps = numDegrees / 15;

    _numScheduledScalings += numSteps;

    if (_numScheduledScalings * numSteps < 0)
        _numScheduledScalings = numSteps;

    auto anim = new QTimeLine{ 350, this };

    connect(anim, &QTimeLine::valueChanged, this, &SceneView::scalingTime);
    connect(anim, &QTimeLine::finished, this, &SceneView::animFinished);

    anim->setUpdateInterval(20);
    anim->start();
}

void SceneView::mouseMoveEvent(QMouseEvent* ev)
{
    const QPointF delta = _targetViewportPos - ev->pos();
    if (qAbs(delta.x()) > 5 || qAbs(delta.y()) > 5)
    {
        _targetViewportPos = ev->pos();
        _targetScenePos = mapToScene(ev->pos());
    }

    QGraphicsView::mouseMoveEvent(ev);
}

void SceneView::mouseDoubleClickEvent(QMouseEvent* ev)
{
    std::ignore = ev;
    resetView();
}

void SceneView::scalingTime(qreal x)
{
    std::ignore = x;

    const qreal factor = 1.0 + static_cast<qreal>(_numScheduledScalings) / 300.0;
    scale(factor, factor);
    scroll();
}

void SceneView::animFinished()
{
    _numScheduledScalings += _numScheduledScalings > 0 ? -1 : 1;
    sender()->deleteLater();
}

void SceneView::scroll()
{
    const QPointF deltaViewportPos = _targetViewportPos - viewport()->rect().center();
    const QPointF viewportCenter = mapFromScene(_targetScenePos) - deltaViewportPos;
    centerOn(mapToScene(viewportCenter.toPoint()));
}
