#include "main_view.h"

int main(int argc, char *argv[])
{
    QApplication app{ argc, argv };

    MainView mainView;
    mainView.show();

    return app.exec();
}
