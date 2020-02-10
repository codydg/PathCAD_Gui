#include "ModelTree.h"

#include <QMenu>
#include <QContextMenuEvent>

#include "PathGroupItem.h"

ModelTree::ModelTree(QWidget* parent) : QTreeView(parent)
{
    newPathGroup = new QAction("New Path Group", this);
    connect(newPathGroup, &QAction::triggered, this, &ModelTree::createNewPathGroup);

    dataModel = new QStandardItemModel();
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