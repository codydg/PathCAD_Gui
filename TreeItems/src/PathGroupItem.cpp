#include "PathGroupItem.h"

#include "PathGroup.h"

#include "LinePathItem.h"

#include <QObject>

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
    QObject::connect(newLine, &QAction::triggered, [this](){newLinePath(const_cast<PathGroupItem*>(this));});
    actions.push_back(newLine);

    // New Path Group
    auto newGroup = new QAction("New Path Group");
    QObject::connect(newGroup, &QAction::triggered, [this](){newPathGroup(const_cast<PathGroupItem*>(this));});
    actions.push_back(newGroup);

    return actions;
}

void PathGroupItem::newLinePath(PathGroupItem* pgi)
{
    auto item = new LinePathItem({}, {}, 0.0);
    pgi->appendRow(item);
    pgi->pathGroup->addPath(item->getPath());
}

void PathGroupItem::newPathGroup(PathGroupItem* pgi)
{
    auto item = new PathGroupItem();
    pgi->appendRow(item);
    pgi->pathGroup->addPath(item->getPath());
}
