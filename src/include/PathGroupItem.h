#pragma once

#include <QStandardItem>

#include "PathGroup.h"
#include "LinePath.h"

class PathGroupItem : public QStandardItem
{
public:
    PathGroupItem();
    virtual ~PathGroupItem() = default;
    void itemChanged();
    void newLinePath(GenericPath::PathElement start, GenericPath::PathElement end, double totalTime);

protected:
    PathGroup pathGroup;
};
