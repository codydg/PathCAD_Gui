#include "MainWindow.h"

#include <QShortcut>
#include <QMessageBox>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("PathCAD");
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(close()));
    auto menuBar = new QMenuBar(this);
    auto fileMenu = menuBar->addMenu("File");
    auto exitAction = fileMenu->addAction("Exit");

    QObject::connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::close()
{
    auto reply = QMessageBox::question(this, "PathCAD", "Are you sure you want to quit?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
        QMainWindow::close();
}
