#pragma once

#include <memory>

#include <QByteArray>

struct Settings
{
    bool askBeforeClosing = true;
    std::unique_ptr<QByteArray> mainSplitterData;
    std::unique_ptr<QByteArray> mainWindowData;

    void read();
    void write();
};
