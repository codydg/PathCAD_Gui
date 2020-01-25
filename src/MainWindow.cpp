#include "MainWindow.h"

#include <QShortcut>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::close()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "PathCAD", "Are you sure you want to quit?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
        QMainWindow::close();
}
