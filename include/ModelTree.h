#pragma once

#include <vector>

#include <QStandardItemModel>
#include <QTreeView>
#include <QWidget>
#include <QAction>

#include "ModelTreeItem.h"

class ModelTree : public QTreeView
{
    Q_OBJECT
public:
    ModelTree(QWidget* parent = nullptr);
    virtual ~ModelTree() = default;

protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif
    void createNewPathGroup();

private slots:
    void itemChanged(QStandardItem* item) const;

private:
    void removeItem(ModelTreeItem* item);
    void addLinePath(ModelTreeItem* item);
    void newLinePath();

protected:
    QStandardItemModel* dataModel;
    QAction* newPathGroupAction;
};