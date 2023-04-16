#include "../widget_serial_port_connection.h"

Widget_serial_port_connection::Widget_serial_port_connection(QWidget *parent) : QWidget(parent)
{
    reader = new serial_port_reader();
    i_adapter* iadp = static_cast<i_adapter*>(reader);
//    this->adp_item->set_items(iadp->get_adapter_item()->get_items());
    adp = iadp->get_adapter_item();
    cb_select_baudrate = new QComboBox(this);
    for(int i = 0; i < m_baudRateList.size(); i++)
        cb_select_baudrate->addItem(QString::number(m_baudRateList.at(i)));
    cb_select_baudrate->setCurrentIndex(m_baudRateList.size() - 1);

    cb_select_port = new QComboBox(this);

    pb_update = new QPushButton(this);
    pb_update->setText("Update");

    pb_connect = new QPushButton(this);
    pb_connect->setText("connect");

    pb_get_config = new QPushButton(this);
    pb_get_config->setText("Get Config");

    pb_start_calibrate = new QPushButton(this);
    pb_start_calibrate->setText("Start Calibrate");

    pb_zeroing = new QPushButton(this);
    pb_zeroing->setText("Zero Pos");

    pb_start_loop_get_data = new QPushButton(this);
    pb_start_loop_get_data->setText("start get data");

    QGridLayout* gridl = new QGridLayout();
    gridl->addWidget(pb_update, 0,0);
    gridl->addWidget(cb_select_port, 1, 0);
    gridl->addWidget(cb_select_baudrate, 1, 1);
    gridl->addWidget(pb_connect, 1, 2);

    gridl->addWidget(pb_get_config, 2, 0, 1, 3);
    gridl->addWidget(pb_start_calibrate, 3, 0, 1, 1);
    gridl->addWidget(pb_zeroing, 3, 1, 1, 3);

    gridl->addWidget(pb_start_loop_get_data, 4, 0, 1, 4);

    this->setLayout(gridl);

    connect(pb_connect, &QPushButton::clicked, this, &Widget_serial_port_connection::connect_to_ports);
    connect(pb_get_config, &QPushButton::clicked, this, &Widget_serial_port_connection::get_config);
    connect(pb_start_calibrate, &QPushButton::clicked, this, &Widget_serial_port_connection::start_calibrate);
    connect(pb_zeroing, &QPushButton::clicked, this, &Widget_serial_port_connection::zeroing);
    connect(pb_start_loop_get_data, &QPushButton::clicked, this, &Widget_serial_port_connection::toggle_loop_get_data);
    connect(pb_update, &QPushButton::clicked, this, &Widget_serial_port_connection::update_available_ports);

    this->update_available_ports();
}


Widget_serial_port_connection::~Widget_serial_port_connection()
{
    this->disconnect_from_ports();
}
