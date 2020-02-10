#include "MainWindow.h"

#include <QShortcut>
#include <QMessageBox>
#include <QMenuBar>
#include <QStatusBar>
#include <QGraphicsView>

#include "SettingsDialog.h"
#include "ModelTree.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    std::unique_lock<decltype(settingsMutex)> settingsLock(settingsMutex);
    settings = std::make_shared<Settings>();
    settings->read();

    // Set window settings
    this->setWindowTitle("PathCAD");
    this->setWindowIcon(QIcon(":icon.png"));

    // Set keyboard listener
    auto exitShortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this);
    auto settingShortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Comma), this);

    // Create MenuBar
    auto menuBar = new QMenuBar();

    auto fileMenu = menuBar->addMenu("File");
    auto exitAction = fileMenu->addAction("Exit\tCtrl+Q");
    auto preferencesAction = fileMenu->addAction("Preferences\tCtrl+,");

    auto helpMenu = menuBar->addMenu("Help");
    auto aboutAction = helpMenu->addAction("About PathCAD");
    auto aboutQtAction = helpMenu->addAction("About Qt");

    this->setMenuBar(menuBar);

    // Create StatusBar
    auto statusBar = new QStatusBar();
    this->setStatusBar(statusBar);

    // Main window area
    mainSplitter = new QSplitter();
    auto modelTree = new ModelTree();
    mainSplitter->addWidget(modelTree);
    auto graphicView = new QGraphicsView();
    mainSplitter->addWidget(graphicView);
    if (settings->mainSplitterData)
        mainSplitter->restoreState(*settings->mainSplitterData);

    this->setCentralWidget(mainSplitter);

    // Create connections
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::aboutUi);
    connect(aboutQtAction, &QAction::triggered, this, &MainWindow::aboutQtUi);
    connect(preferencesAction, &QAction::triggered, this, &MainWindow::settingsUi);

    connect(exitShortcut, &QShortcut::activated, this, &MainWindow::close);
    connect(settingShortcut, &QShortcut::activated, this, &MainWindow::settingsUi);
}

MainWindow::~MainWindow()
{
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    std::unique_lock<decltype(settingsMutex)> settingsLock(settingsMutex);

    auto reply = QMessageBox::Yes;
    if (settings->askBeforeClosing)
        reply = QMessageBox::question(this, "PathCAD", "Are you sure you want to quit?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        settings->mainSplitterData = std::make_unique<QByteArray>(mainSplitter->saveState());
        settings->write();
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::aboutUi()
{
    QMessageBox::about(this, "PathCAD", "PathCAD is a 2-Dimensional CAD program for the development of paths.");
}

void MainWindow::aboutQtUi()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::settingsUi()
{
    std::unique_lock<decltype(settingsMutex)> settingsLock(settingsMutex);
    SettingsDialog settingsDialog(settings, this);
    settingsDialog.exec();
}
