#include "node.h"
#include "scene.h"

namespace
{
    class BoolGuard
    {
    public:
        BoolGuard(bool& value)
            : _value{ value }
        {
            _value = true;
        }

        ~BoolGuard()
        {
            _value = false;
        }

    private:
        bool _value;
    };
}

Scene::Scene(QObject* parent)
    : SceneImg{ parent }
{
   _nodes.setParent(_pixmapItem);
   _nodesArea = addPolygon(_nodes.polygon(), {}, QColor{ 255, 255, 0, 150 });
   _nodesArea->setFillRule(Qt::WindingFill);
}

void Scene::load(const QString& path)
{
    BoolGuard guard{ _isLoading };
    SceneImg::load(path);
    _nodes.arrange(_pixmapItem->boundingRect());
}

QPolygonF Scene::polygon() const
{
    return _nodesArea->polygon();
}

void Scene::onNodeMove()
{
    _nodesArea->setPolygon(_nodes.polygon());
    if (!_isLoading)
        emit changed();
}
