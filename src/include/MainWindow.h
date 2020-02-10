#pragma once

#include <shared_mutex>
#include <memory>

#include <QMainWindow>
#include <QCloseEvent>
#include <QWidget>
#include <QSplitter>

#include "Settings.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

public Q_SLOTS:
    virtual void closeEvent(QCloseEvent *event) override;
    void aboutUi();
    void aboutQtUi();
    void settingsUi();

private:
    std::shared_mutex settingsMutex;
    std::shared_ptr<Settings> settings;

    // For settings storage
    QSplitter* mainSplitter;
};
