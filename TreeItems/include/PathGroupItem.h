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
    virtual QList<QAction*> getContextActions() const override;

    // Non-virtual functions
    static void newLinePath(PathGroupItem* pgi);
    static void newPathGroup(PathGroupItem* pgi);

protected:
    std::shared_ptr<PathGroup> pathGroup;
};
