#include "ModelTree.h"

#include <QMenu>
#include <QContextMenuEvent>

ModelTree::ModelTree(QWidget* parent) : QTreeView(parent)
{
    setEditTriggers(EditTrigger::EditKeyPressed);

    newPathGroup = new QAction("New Path Group", this);
    connect(newPathGroup, &QAction::triggered, this, &ModelTree::createNewPathGroup);

    dataModel = new QStandardItemModel();
    dataModel->setHorizontalHeaderLabels({"Model Tree"});
    connect(dataModel, &QStandardItemModel::itemChanged, this, &ModelTree::itemChanged);
    setModel(dataModel);
}

#ifndef QT_NO_CONTEXTMENU
void ModelTree::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(newPathGroup);
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
