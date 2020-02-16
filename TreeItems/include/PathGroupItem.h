#pragma once

#include "ModelTreeItem.h"

class PathGroup;

class PathGroupItem : public ModelTreeItem
{
public:
    PathGroupItem();

    // Overriden Pure Virtual functions
    virtual void itemChanged() override;
    virtual std::shared_ptr<GenericPath> getPath() const override;

    // Overriden Virtual functions
    virtual void removeItem(ModelTreeItem* item) override;
    virtual QList<QAction*> createContextActions() override;

    // Non-virtual functions
    void newLinePath();
    void newPathGroup();

protected:
    std::shared_ptr<PathGroup> pathGroup;
};
