#include "ModelTree.h"

#include <QMenu>
#include <QContextMenuEvent>

ModelTree::ModelTree(QWidget* parent) : QTreeView(parent)
{
    setEditTriggers(EditTrigger::EditKeyPressed);

    newPathGroupAction = new QAction("New Path Group", this);
    connect(newPathGroupAction, &QAction::triggered, this, &ModelTree::createNewPathGroup);

    dataModel = new QStandardItemModel();
    dataModel->setHorizontalHeaderLabels({"Model Tree"});
    connect(dataModel, &QStandardItemModel::itemChanged, this, &ModelTree::itemChanged);
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
        auto item = dynamic_cast<PathGroupItem*>(dataModel->itemFromIndex(itemIndex));
        auto lineAction = menu.addAction("New Line Path");
        connect(lineAction, &QAction::triggered, [item = item](){ item->newLinePath({}, {}, 0.0); });
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
    dynamic_cast<PathGroupItem*>(item)->itemChanged();
}
