#include "LinePathItem.h"

LinePathItem::LinePathItem(GenericPath::PathElement start, GenericPath::PathElement end, double totalTime) :
        ModelTreeItem(ModelTreeItemId::LINE_PATH)
{
    linePath = std::make_shared<LinePath>(start, end, totalTime);
    setText(QString::fromStdString(linePath->getName()));
}

void LinePathItem::itemChanged()
{
    linePath->setName(text().toStdString());
}

std::shared_ptr<GenericPath> LinePathItem::getPath() const
{
    return linePath;
}
