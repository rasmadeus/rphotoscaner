#ifndef SCENE_IMG_H
#define SCENE_IMG_H

#include <QObject>

class SceneImg : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit SceneImg(QObject* parent = nullptr);
    virtual void load(const QString& path);
    void setPixmap(const QPixmap &pixmap);
    const QPixmap& pixmap() const;

protected:
    QGraphicsPixmapItem* _pixmapItem;
    QPixmap _pixmap;
};

#endif // SCENE_IMG_H
