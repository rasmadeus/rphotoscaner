#include "img_transformator.h"
#include "main_view.h"

MainView::MainView(QWidget* parent)
    : QMainWindow{ parent }
{
    _ui.setupUi(this);
    _ui.srcImgView->setScene(&_srcImgScene);
    _ui.resImgView->setScene(&_resImgScene);

    connect(_ui.loadImgBtn, &QPushButton::clicked, this, &MainView::load);
    connect(_ui.saveImgBtn, &QPushButton::clicked, this, &MainView::save);
    connect(&_srcImgScene, &Scene::changed, this, &MainView::makeRes);
    connect(_ui.widthSpinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &MainView::makeRes);
    connect(_ui.heightSpinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &MainView::makeRes);
}

void MainView::load()
{
    const auto path = QFileDialog::getOpenFileName(this, tr("Select an image..."), {}, tr("Images (*png *jpg *jpeg)"));
    if (!path.isEmpty())
    {
        _srcImgScene.load(path);
        _ui.srcImgView->resetView();
    }
}

void MainView::save()
{
    const auto path = QFileDialog::getSaveFileName(this, tr("Select an image..."));
    if (!path.isEmpty())
        _resImgScene.pixmap().toImage().save(path);
}

void MainView::makeRes()
{
    ImgTransformator imgTransformator{ _srcImgScene.pixmap(), _srcImgScene.polygon() };
    QPixmap res = imgTransformator.get(_ui.widthSpinBox->value(), _ui.heightSpinBox->value());

    if (res.isNull())
        QMessageBox::warning(this, tr("Error"), tr("Incorrect point destination"));
    else
        _resImgScene.setPixmap(std::move(res));
}
