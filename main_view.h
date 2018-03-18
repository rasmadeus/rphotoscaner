#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H

#include "ui_main_view.h"
#include "scene.h"
#include "scene_img.h"

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget* parent = nullptr);

private:
    void load();
    void save();
    void makeRes();

private:
    Ui::MainView _ui;
    Scene _srcImgScene;
    SceneImg _resImgScene;
};

#endif // MAIN_VIEW_H
