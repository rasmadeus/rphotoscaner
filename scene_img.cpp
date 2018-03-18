#include "scene_img.h"

SceneImg::SceneImg(QObject* parent)
    : QGraphicsScene{ parent }
{
    _pixmapItem = addPixmap({});
}

void SceneImg::load(const QString& path)
{
    setPixmap({ path });
}

void SceneImg::setPixmap(const QPixmap& pixmap)
{
    _pixmap = pixmap;
    _pixmapItem->setPixmap(pixmap);
    setSceneRect(_pixmapItem->boundingRect());
}

const QPixmap& SceneImg::pixmap() const
{
    return _pixmap;
}
