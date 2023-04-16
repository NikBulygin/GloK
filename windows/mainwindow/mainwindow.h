#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "../../item/adapter_item.h"
#include "../3dgraphics/widget3d.h"
#include "../side/side.h"
#include "../widget_gesture_handler/widget_gesture_handler.h"


#include <QMainWindow>
#include <QtWidgets>

class MainWidget : public QMainWindow
{
private:\
    side* side_widtet;
    widget3d* widg3d;
    Widget_Gesture_Handler* wgh;
public:
    MainWidget(QWidget* parent = nullptr);
};

#endif // MAINWINDOW_H
