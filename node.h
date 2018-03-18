#ifndef NODE_H
#define NODE_H

class Node : public QGraphicsItem
{
public:
    Node();

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* ev) override;
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant& value) override;
};

#endif // NODE_H
