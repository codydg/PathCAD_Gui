#include "PathGroupItem.h"

#include "PathGroup.h"

#include "LinePathItem.h"

PathGroupItem::PathGroupItem() : ModelTreeItem(ModelTreeItemId::PATH_GROUP)
{
    pathGroup = std::make_shared<PathGroup>();

    setText(QString::fromStdString(pathGroup->getName()));
}

void PathGroupItem::itemChanged()
{
    pathGroup->setName(text().toStdString());
}

std::shared_ptr<GenericPath> PathGroupItem::getPath() const
{
    return pathGroup;
}

void PathGroupItem::removeItem(ModelTreeItem* item)
{
    // TODO: Remove item from `pathGroup`
    removeRow(item->row());
}

QList<QAction*> PathGroupItem::getContextActions() const
{
    QList<QAction*> actions;

    // New Line Path
    auto newLine = new QAction("New Line Path");
    connect(newLine, &QAction::triggered, std::bind(&PathGroupItem::newLinePath, this));
    actions.push_back(newLine);

    // New Path Group
    auto newGroup = new QAction("New Path Group");
    connect(newGroup, &QAction::triggered, std::bind(&PathGroupItem::newPathGroup, this));
    actions.push_back(newGroup);

    return actions;
}

void PathGroupItem::newLinePath()
{
    auto item = new LinePathItem({}, {}, 0.0);
    this->appendRow(item);
    pathGroup->addPath(item->getPath());
}

void PathGroupItem::newPathGroup()
{
    auto item = new PathGroupItem();
    this->appendRow(item);
    pathGroup->addPath(item->getPath());
}
