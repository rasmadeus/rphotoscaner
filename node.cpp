#include "node.h"
#include "scene.h"

Node::Node()
    : QGraphicsItem{}
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
}

QRectF Node::boundingRect() const
{
    return { -5.0, -5.0, 10.0, 10.0 };
}

void Node::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    std::ignore = widget;

    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkRed);
    painter->drawEllipse(boundingRect());

    QRadialGradient gradient{ -3, -3, 10 };
    if (option->state & QStyle::State_Sunken)
    {
        gradient.setCenter(3, 3);
        gradient.setFocalPoint(3, 3);
        gradient.setColorAt(1, Qt::green);
        gradient.setColorAt(0, Qt::darkGreen);
    }
    else
    {
        gradient.setColorAt(0, QColor{ Qt::green }.light(120));
        gradient.setColorAt(1, QColor{ Qt::darkGreen }.light(120));
    }
}

void Node::mouseMoveEvent(QGraphicsSceneMouseEvent* ev)
{
    QGraphicsItem::mouseMoveEvent(ev);

    if (x() < 0.0)
        setPos(0.0, y());
    else if (x() + boundingRect().right() > scene()->width())
        setPos(scene()->width(), y());

    if (y() < 0.0)
        setPos(x(), 0.0);
    else if (y()+ boundingRect().bottom() > scene()->height())
        setPos(x(), scene()->height());
}

QVariant Node::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant& value)
{
    if (change == QGraphicsItem::ItemPositionHasChanged)
        static_cast<Scene*>(scene())->onNodeMove();

    return QGraphicsItem::itemChange(change, value);
}
