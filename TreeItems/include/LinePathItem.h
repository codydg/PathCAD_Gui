#pragma once

#include "LinePath.h"

#include "ModelTreeItem.h"

#include <memory>

class LinePathItem : public ModelTreeItem
{
public:
    LinePathItem(PathElement start, PathElement end, double totalTime);

    // Overriden Pure Virtual functions
    virtual void itemChanged() override;
    virtual std::shared_ptr<GenericPath> getPath() const override;

    // Overriden Virtual functions
    // No defined virtual functions are currently overriden.

protected:
    std::shared_ptr<LinePath> linePath;
};
