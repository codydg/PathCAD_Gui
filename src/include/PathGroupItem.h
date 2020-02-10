#pragma once

#include <QStandardItem>

#include "PathGroup.h"

class PathGroupItem : public QStandardItem
{
public:
    PathGroupItem();
    virtual ~PathGroupItem() = default;
protected:
    PathGroup pathGroup;
};
