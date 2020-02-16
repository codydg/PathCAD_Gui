#include "ModelTree.h"

#include <iostream>

#include <QMenu>
#include <QContextMenuEvent>

#include "PathGroupItem.h"

ModelTree::ModelTree(QWidget* parent) : QTreeView(parent)
{
    setEditTriggers(EditTrigger::EditKeyPressed);
    setItemsExpandable(false);

    newPathGroupAction = new QAction("New Path Group", this);
    connect(newPathGroupAction, &QAction::triggered, this, &ModelTree::createNewPathGroup);

    dataModel = new QStandardItemModel();
    dataModel->setHorizontalHeaderLabels({"Model Tree"});
    connect(dataModel, &QStandardItemModel::itemChanged, this, &ModelTree::itemChanged);
    connect(dataModel, &QStandardItemModel::rowsInserted, [view = this](const QModelIndex &parent, int first, int last){ view->expand(parent); });
    setModel(dataModel);
}

#ifndef QT_NO_CONTEXTMENU
void ModelTree::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    auto itemIndex = indexAt(event->pos());
    if (itemIndex.isValid())
    {
        // User right-clicked item in tree
        auto item = dynamic_cast<ModelTreeItem*>(dataModel->itemFromIndex(itemIndex));

        // Add item-dependant actions
        menu.addActions(item->createContextActions());

        // Add delete action
        auto deleteAction = menu.addAction("Delete");
        auto rawItemParent = item->parent();
        if (rawItemParent)
        {
            auto itemParent = dynamic_cast<ModelTreeItem*>(rawItemParent);
            connect(deleteAction, &QAction::triggered,
                    std::bind(&ModelTreeItem::removeItem, itemParent, item));
        }
        else
        {
            connect(deleteAction, &QAction::triggered,
                    std::bind(&ModelTree::removeItem, this, item));
        }
    }
    else
    {
        // User right-clicked tree
        menu.addAction(newPathGroupAction);
    }
    menu.exec(event->globalPos());
}
#endif

void ModelTree::createNewPathGroup()
{
    dataModel->appendRow(new PathGroupItem());
}

void ModelTree::itemChanged(QStandardItem* item) const
{
    dynamic_cast<ModelTreeItem*>(item)->itemChanged();
}

void ModelTree::removeItem(ModelTreeItem* item)
{
    dataModel->removeRow(item->row());
}

void ModelTree::addLinePath(ModelTreeItem* item)
{
    const auto& id = item->getId();
    switch (id)
    {
        case ModelTreeItemId::PATH_GROUP:
            dynamic_cast<PathGroupItem*>(item)->newLinePath();
            break;
        case ModelTreeItemId::LINE_PATH:
            throw std::runtime_error("Cannot add Line Path to ModelTreeItem type: " + static_cast<int>(id));
            break;
        default:
            std::cout << "Warning: Unknown ModelTreeItem type: " << static_cast<int>(id) << std::endl;
    }
}

void ModelTree::newLinePath()
{

}
