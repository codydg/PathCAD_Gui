#pragma once

#include <mutex>

#include <QMainWindow>
#include <QCloseEvent>
#include <QWidget>

#include "Settings.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public Q_SLOTS:
    virtual void closeEvent(QCloseEvent *event) override;
    void aboutUi();
    void aboutQtUi();
    void settingsUi();

private:
    std::mutex settingsMutex;
    std::shared_ptr<Settings> settings;
};
