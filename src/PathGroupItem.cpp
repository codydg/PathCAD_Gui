#include "PathGroupItem.h"

PathGroupItem::PathGroupItem()
{
    setText(QString::fromStdString(pathGroup.getName()));
}
