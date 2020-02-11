#include "Settings.h"

#include <QSettings>
#include <QCoreApplication>

void Settings::read()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    settings.beginGroup("General");
    askBeforeClosing = settings.value("askBeforeClosing", askBeforeClosing).toBool();
    settings.endGroup();

    settings.beginGroup("System");
    if (settings.contains("mainWindowData"))
        mainWindowData = std::make_unique<QByteArray>(settings.value("mainWindowData").toByteArray());
    if (settings.contains("mainSplitterData"))
        mainSplitterData = std::make_unique<QByteArray>(settings.value("mainSplitterData").toByteArray());
    settings.endGroup();
}
void Settings::write()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    settings.beginGroup("General");
    settings.setValue("askBeforeClosing", askBeforeClosing);
    settings.endGroup();

    settings.beginGroup("System");
    if (mainWindowData)
        settings.setValue("mainWindowData", *mainWindowData);
    if (mainSplitterData)
        settings.setValue("mainSplitterData", *mainSplitterData);
    settings.endGroup();
}
