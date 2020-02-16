#pragma once

#include <memory>

#include <QStandardItem>
#include <QAction>
#include <QList>

#include "GenericPath.h"

enum class ModelTreeItemId
{
    PATH_GROUP,
    LINE_PATH
};

class ModelTreeItem : public QStandardItem
{
public:
    ModelTreeItem(ModelTreeItemId id);

    // Pure Virtual functions
    virtual void itemChanged() = 0;
    virtual std::shared_ptr<GenericPath> getPath() const = 0;

    // Defined Virtual functions
    virtual void removeItem(ModelTreeItem* item);
    virtual QList<QAction*> createContextActions();

    // Non-virtual functions
    ModelTreeItemId getId() const;

protected:
    const ModelTreeItemId id;
};
