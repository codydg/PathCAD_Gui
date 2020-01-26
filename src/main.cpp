#include <QApplication>

#include "MainWindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QCoreApplication::setOrganizationName("PathCAD");
    QCoreApplication::setApplicationName("PathCAD");

    MainWindow main;
    main.show();

    return app.exec();
}
