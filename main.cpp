#include <QApplication>
#include <QEventLoop>
#include <QTimer>

#include "windows/mainwindow/mainwindow.h"
#include "adapters/file_reader/file_reader_adapter.h"
#include "adapters/i_adapter.h"
#include "item/adapter_item.h"
#include "item/item.h"

#include "adapters/serial_port_redaer/serial_port_reader.h"

#include "windows/widget_gesture_handler/widget_gesture_handler.h"

adapter_item* adp = new adapter_item(0);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWidget w;
    w.show();

    return a.exec();
}
