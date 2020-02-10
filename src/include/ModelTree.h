#pragma once

#include <vector>

#include <QStandardItemModel>
#include <QTreeView>
#include <QWidget>
#include <QAction>

#include "GenericPath.h"

class ModelTree : public QTreeView
{
public:
    ModelTree(QWidget* parent = nullptr);
    virtual ~ModelTree() = default;

protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif
    void createNewPathGroup();

    QStandardItemModel* dataModel;
    QAction* newPathGroup;
};