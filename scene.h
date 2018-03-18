#ifndef SCENE_H
#define SCENE_H

#include "nodes.h"
#include "scene_img.h"

class Scene : public SceneImg
{
    Q_OBJECT

public:
    explicit Scene(QObject* parent = nullptr);

    void load(const QString& path) override;

    QPolygonF polygon() const;
    void onNodeMove();

signals:
    void changed();

private:
    Nodes _nodes;
    QGraphicsPolygonItem* _nodesArea;
    bool _isLoading{ false };
};

#endif // SCENE_H
