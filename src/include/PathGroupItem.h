#pragma once

#include <QStandardItem>

#include "PathGroup.h"

class PathGroupItem : public QStandardItem
{
public:
    PathGroupItem();
    virtual ~PathGroupItem() = default;
    void itemChanged();

protected:
    PathGroup pathGroup;
};
