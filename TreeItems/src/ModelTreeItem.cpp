#include "ModelTreeItem.h"

#include <stdexcept>
#include <sstream>

ModelTreeItem::ModelTreeItem(ModelTreeItemId id) : id(id) { }

void ModelTreeItem::removeItem(ModelTreeItem* item)
{
    std::stringstream error;
    error << "Item of type " << static_cast<int>(item->getId()) << " has not defined a removal function.";
    throw std::runtime_error(error.str());
}

QList<QAction*> ModelTreeItem::getContextActions() const
{
    return QList<QAction*>();
}

ModelTreeItemId ModelTreeItem::getId() const
{
    return id;
}
