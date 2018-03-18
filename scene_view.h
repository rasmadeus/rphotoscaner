#ifndef SCENE_VIEW_H
#define SCENE_VIEW_H

class SceneView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit SceneView(QWidget* parent);
    void resetView();

protected:
    void wheelEvent(QWheelEvent* ev) override;
    void mouseMoveEvent(QMouseEvent* ev) override;
    void mouseDoubleClickEvent(QMouseEvent* ev) override;

private:
    void scalingTime(qreal x);
    void animFinished();
    void scroll();

private:
    int _numScheduledScalings{};
    QPointF _targetScenePos;
    QPointF _targetViewportPos;
};

#endif // SCENE_VIEW_H
