#pragma once

#include "GenericPath.h"

#include "ModelTreeItem.h"

#include <memory>

class DataElementItem : public ModelTreeItem
{
public:
    DataElementItem(DataElement dataElement);

    // Overriden Pure Virtual functions
    virtual void itemChanged() override;
    virtual std::shared_ptr<GenericPath> getPath() const override;

    // Overriden Virtual functions
    virtual QList<QAction*> createContextActions() override;

    // Non-virtual functions
    void setValueMenu();

protected:
    std::shared_ptr<DataElement> dataElement;
};
