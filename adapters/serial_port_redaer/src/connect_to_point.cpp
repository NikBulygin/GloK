#include "../serial_port_reader.h"

void serial_port_reader::connect_to_point(int i, QString password )
{
    qDebug() << this->available_Ports->at(i);
    this->serialPort->setPortName(this->available_Ports->at(i));
    this->serialPort->setBaudRate(this->baudrate);

    if (!this->serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Не удалось открыть порт: ";
    }


    connect(this, &serial_port_reader::dataRecieved, this, &serial_port_reader::handleNewData);
    connect(this->serialPort, &QSerialPort::readyRead, this, &serial_port_reader::readnew_data);
}


void serial_port_reader::disconnect_from_point()
{
    this->serialPort->close();
}
bool serial_port_reader::is_connected_to_point()
{
    return this->serialPort->isOpen();
}
