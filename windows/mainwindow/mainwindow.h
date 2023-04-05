#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../../item/adapter_item.h"
#include "../3dgraphics/widget3d.h"
#include "../side/side.h"

#include <QMainWindow>
#include <QtWidgets>

class MainWidget : public QMainWindow
{
private:
    adapter_item* adp_item;
    side* side_widtet;
    widget3d* widg3d;
public:
    MainWidget(adapter_item* adp_item = nullptr, QWidget* parent = nullptr);
    adapter_item* get_adapter()
    {
        return this->adp_item;
    }
};

#endif // MAINWINDOW_H
