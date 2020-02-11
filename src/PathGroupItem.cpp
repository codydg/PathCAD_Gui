#include "PathGroupItem.h"

PathGroupItem::PathGroupItem()
{
    setText(QString::fromStdString(pathGroup.getName()));
}

void PathGroupItem::itemChanged()
{
    pathGroup.setName(text().toStdString());
}

void PathGroupItem::newLinePath(GenericPath::PathElement start, GenericPath::PathElement end, double totalTime)
{
    pathGroup.addPath(std::make_shared<LinePath>(start, end, totalTime));
}
