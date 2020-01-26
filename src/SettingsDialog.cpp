#include "SettingsDialog.h"

#include <QShortcut>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QVBoxLayout>

SettingsDialog::SettingsDialog(std::shared_ptr<Settings> settings, QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f), settings(settings)
{
    init();
}

SettingsDialog::SettingsDialog(std::shared_ptr<Settings> settings, QWidget *parent) : QDialog(parent), settings(settings)
{
    init();
}

void SettingsDialog::applyChanges()
{
    settings->askBeforeClosing = askBeforeClosingBox->isChecked();
}

void SettingsDialog::accept()
{
    applyChanges();
    QDialog::accept();
}

void SettingsDialog::init()
{
    // Create closing shortcut
    auto exitShortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this);

    // Create Dialog buttons
    auto buttons = new QDialogButtonBox(QDialogButtonBox::Ok |
                                        QDialogButtonBox::Cancel |
                                        QDialogButtonBox::Apply);
    auto applyButton = buttons->button(QDialogButtonBox::Apply);

    // Create setting-specific content
    askBeforeClosingBox = new QCheckBox("Confirm before exiting");

    // Set setting-specific items to current settings
    askBeforeClosingBox->setChecked(settings->askBeforeClosing);

    // Create layout
    auto layout = new QVBoxLayout(this);
    layout->addWidget(askBeforeClosingBox);
    layout->addWidget(buttons);

    // Make connections
    connect(buttons, &QDialogButtonBox::accepted, this, &SettingsDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, this, &SettingsDialog::reject);
    connect(applyButton, &QPushButton::pressed, this, &SettingsDialog::applyChanges);
    connect(exitShortcut, &QShortcut::activated, this, &SettingsDialog::reject);
}
