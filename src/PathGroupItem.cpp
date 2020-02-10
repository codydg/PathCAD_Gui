#include "PathGroupItem.h"

PathGroupItem::PathGroupItem()
{
    setText(QString::fromStdString(pathGroup.getName()));
}

void PathGroupItem::itemChanged()
{
    pathGroup.setName(text().toStdString());
}
