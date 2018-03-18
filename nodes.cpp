#include "nodes.h"

Node* Nodes::node(Nodes::Pos pos) const
{
    auto i = static_cast<const std::size_t>(pos);
    return _nodes[i];
}

QPolygonF Nodes::polygon() const
{
    QVector<QPointF> vertexes;
    for(auto node : _nodes)
        vertexes << node->pos();

    return { std::move(vertexes) };
}

void Nodes::setParent(QGraphicsItem* item)
{
    for(auto node : _nodes)
        node->setParentItem(item);
}

void Nodes::arrange(const QRectF& rect)
{
    node(Pos::TopLeft)->setPos(rect.topLeft());
    node(Pos::TopRight)->setPos(rect.topRight());
    node(Pos::BottomRight)->setPos(rect.bottomRight());
    node(Pos::BottomLeft)->setPos(rect.bottomLeft());
}
