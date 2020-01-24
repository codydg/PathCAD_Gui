#include "MainWindow.h"

#include <QShortcut>
#include <iostream>

MainWindow::MainWindow()
{
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(close()));
}