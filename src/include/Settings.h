#pragma once

struct Settings
{
    bool askBeforeClosing = true;

    void read();
    void write();
};
