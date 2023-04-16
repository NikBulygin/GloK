#ifndef WIDGET_SERIAL_PORT_CONNECTION_H
#define WIDGET_SERIAL_PORT_CONNECTION_H

#include <QList>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QShortcut>

#include "../../../../item/adapter_item.h"
#include "../../../../adapters/serial_port_redaer/serial_port_reader.h"

extern adapter_item* adp ;
class Widget_serial_port_connection : public QWidget
{
    Q_OBJECT
protected:
    serial_port_reader* reader;
    QComboBox* cb_select_port;
    QComboBox* cb_select_baudrate;
    QPushButton* pb_update;
    QPushButton* pb_connect;
    QPushButton* pb_get_config;
    QPushButton* pb_start_calibrate;
    QPushButton* pb_zeroing;
    QPushButton* pb_start_loop_get_data;
private:
    const QList<int> m_baudRateList = {9600, 19200, 38400, 57600, 115200};
    bool flag_loop_get_data = false;
public:
    Widget_serial_port_connection(QWidget* parent = nullptr);
    ~Widget_serial_port_connection();
protected slots:
    void update_available_ports();
    void connect_to_ports();
    void disconnect_from_ports();
    void get_config();
    void start_calibrate();
    void zeroing();
    void toggle_loop_get_data();

signals:


};

#endif // WIDGET_SERIAL_PORT_CONNECTION_H
