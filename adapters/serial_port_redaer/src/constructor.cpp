#include "../serial_port_reader.h"

serial_port_reader::serial_port_reader()
{
    this->serialPort = new QSerialPort(this);
    this->available_Ports = new QVector<QString>;
    this->baudrate = QSerialPort::Baud115200;
    this->serialPort->setBaudRate(baudrate);
    this->serialPort->setDataBits(QSerialPort::Data8);
//    this->serialPort->setParity(QSerialPort::NoParity);
//    this->serialPort->setStopBits(QSerialPort::OneStop);
    this->serialPort->setFlowControl(QSerialPort::NoFlowControl);
}
