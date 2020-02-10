#pragma once

#include <memory>

#include <QDialog>
#include <QCheckBox>

#include "Settings.h"

class SettingsDialog : public QDialog
{
public:
    explicit SettingsDialog(std::shared_ptr<Settings> settings, QWidget *parent, Qt::WindowFlags f);
    explicit SettingsDialog(std::shared_ptr<Settings> settings, QWidget *parent = nullptr);
    virtual ~SettingsDialog() = default;

public Q_SLOTS:
    virtual void applyChanges();
    virtual void accept() override;

private:
    void init();

    std::shared_ptr<Settings> settings;
    QCheckBox* askBeforeClosingBox;
};
