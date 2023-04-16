#include "../widget_serial_port_connection.h"

void Widget_serial_port_connection::update_available_ports()
{
    cb_select_port->clear();
    QVector<QString> pointsname = reader->get_name_points();
    for(int i = 0; i < pointsname.size(); i++)
    {
        cb_select_port->addItem(pointsname.at(i));
    }

}
void Widget_serial_port_connection::connect_to_ports()
{
    this->reader->disconnect();
    if(!this->reader->is_connected_to_point())
    {
        this->reader->set_baudrate(static_cast<QSerialPort::BaudRate>(cb_select_baudrate->currentText().toInt()));
        this->reader->connect_to_point(cb_select_port->currentIndex());
        this->pb_connect->setText(
                this->reader->is_connected_to_point() ? "disconnected" : "failed"
                );
    }
    else {
        disconnect_from_ports();
    }
}
void Widget_serial_port_connection::disconnect_from_ports()
{
    this->reader->disconnect();
    this->pb_connect->setText("connect");
}
void Widget_serial_port_connection::get_config()
{
    this->reader->send_data("{\"config\":1}");
}
void Widget_serial_port_connection::start_calibrate()
{
    this->reader->send_data("{\"start_calibrate\":1}");
}
void Widget_serial_port_connection::zeroing()
{
    this->reader->send_data("{\"zero_data\":1}");
}

void Widget_serial_port_connection::toggle_loop_get_data()
{
    this->flag_loop_get_data = !this->flag_loop_get_data;
    this->pb_get_config->setEnabled(this->flag_loop_get_data);
    this->pb_start_calibrate->setEnabled(this->flag_loop_get_data);
    this->pb_start_loop_get_data->setText("Stop");

//    this->reader->send_data("{\"data\":1");
    if(!flag_loop_get_data)
    {
        this->reader->send_data("{\"start_loop_get_data\":1}");
        this->pb_start_loop_get_data->setText("start");
    }
    else
    {
        this->reader->send_data("{\"start_loop_get_data\":0}");
        this->pb_start_loop_get_data->setText("stop");
    }
}
