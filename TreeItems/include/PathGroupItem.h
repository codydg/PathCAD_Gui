#pragma once

#include <QObject>

#include "ModelTreeItem.h"

class PathGroup;

class PathGroupItem : public QObject, public ModelTreeItem
{
    Q_OBJECT
public:
    PathGroupItem();

    // Overriden Pure Virtual functions
    virtual void itemChanged() override;
    virtual std::shared_ptr<GenericPath> getPath() const override;

    // Overriden Virtual functions
    virtual void removeItem(ModelTreeItem* item) override;
    virtual QList<QAction*> getContextActions() const override;

    // Non-virtual functions
    void newLinePath();
    void newPathGroup();

protected:
    std::shared_ptr<PathGroup> pathGroup;
};
