#ifndef SIDE_H
#define SIDE_H

#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QScrollArea>


#include "item_widget_settings/item_widget.h"
#include "item_widget_settings/widget_serial_port_connection/widget_serial_port_connection.h"
#include "../../item/adapter_item.h"

extern adapter_item* adp;
class side : public QWidget
{
    Q_OBJECT
protected:
    Widget_serial_port_connection* wspc;
    QVBoxLayout* scrolllayout;
    QListWidget* qlw;
protected slots:
    void update_scroll();
public:
    side(QWidget* parent = nullptr);
};

#endif // SIDE_H
