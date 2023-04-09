#include <QApplication>
#include <QEventLoop>
#include <QTimer>

#include "windows/mainwindow/mainwindow.h"
#include "adapters/file_reader/file_reader_adapter.h"
#include "adapters/i_adapter.h"
#include "item/adapter_item.h"
#include "item/item.h"

#include "adapters/serial_port_redaer/serial_port_reader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    serial_port_reader reader;
    reader.set_baudrate(QSerialPort::Baud115200);
    reader.get_name_points();
    reader.connect_to_point(reader.get_point_by_name(QString::fromUtf8("ttyUSB0")));
//    //wait get config data
    QEventLoop loop;
    QObject::connect(&reader, &serial_port_reader::config_was_accepted, &loop, &QEventLoop::quit);\
    reader.send_data("{\"config\":1}");
    loop.exec();

////    file_reader_adapter reader;
////    reader.read_config();

    i_adapter* iadp = static_cast<i_adapter*>(&reader);
    adapter_item* adp = iadp->get_adapter_item();

//    adapter_item* adp = new adapter_item();
    MainWidget w(adp);
    w.show();

    reader.send_data("{\"start_calibrate\":1}");
    QTimer::singleShot(20000, &loop, &QEventLoop::quit);
    loop.exec();
    reader.send_data("{\"start_loop_get_data\":1}");
//    QTimer timer;
//    timer.setInterval(500);
//    QObject::connect(&timer, &QTimer::timeout, &reader, &serial_port_reader::request_data);
//    reader.request_data();
//    timer.start();
    return a.exec();
}
