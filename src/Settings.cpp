#include "Settings.h"

#include <QSettings>
#include <QCoreApplication>

void Settings::read()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    settings.beginGroup("General");
    askBeforeClosing = settings.value("askBeforeClosing", askBeforeClosing).toBool();
    settings.endGroup();
}
void Settings::write()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    settings.beginGroup("General");
    settings.setValue("askBeforeClosing", askBeforeClosing);
    settings.endGroup();
}