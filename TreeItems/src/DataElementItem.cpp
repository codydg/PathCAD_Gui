#include "DataElementItem.h"

#include <QObject>

DataElementItem::DataElementItem(DataElement dataElement) :
        ModelTreeItem(ModelTreeItemId::DATA_ELEMENT)
{
    this->dataElement = std::make_shared<DataElement>(dataElement);
    //setText(QString::fromStdString());
}

void DataElementItem::itemChanged()
{
    //->setName(text().toStdString());
}

std::shared_ptr<GenericPath> DataElementItem::getPath() const
{
    return nullptr;
}

QList<QAction*> DataElementItem::createContextActions()
{
    QList<QAction*> actions;

    // Set value of data element
    auto setValue = new QAction("Set value");
    QObject::connect(setValue, &QAction::triggered, std::bind(&DataElementItem::setValueMenu, this));
    actions.push_back(setValue);

    return actions;
}

void DataElementItem::setValueMenu()
{

}
