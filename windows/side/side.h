#ifndef SIDE_H
#define SIDE_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QPushButton>
#include <QScrollArea>

#include "item_widget_settings/item_widget.h"
#include "../../item/adapter_item.h"
class side : public QWidget
{
    Q_OBJECT
protected:
    adapter_item* adp_item;
    QListWidget* qlw;
public:
    side(adapter_item* adp_item, QWidget* parent = nullptr);
};

#endif // SIDE_H
