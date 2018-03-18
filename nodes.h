#ifndef NODES_H
#define NODES_H

#include "node.h"

class Nodes
{
public:
    enum class Pos : std::size_t
    {
        TopLeft,
        TopRight,
        BottomRight,
        BottomLeft,
    };

public:
    Node* node(Nodes::Pos pos) const;
    QPolygonF polygon() const;

    void setParent(QGraphicsItem* item);
    void arrange(const QRectF& rect);

private:
    std::array<Node*, 4> _nodes{ { new Node{}, new Node{}, new Node{}, new Node{} } };
};

#endif // NODES_H
