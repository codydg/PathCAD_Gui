#pragma once

#include <memory>

#include <QByteArray>

struct Settings
{
    bool askBeforeClosing = true;
    std::unique_ptr<QByteArray> mainSplitterData;

    void read();
    void write();
};
