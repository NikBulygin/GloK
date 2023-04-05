#include "../serial_port_reader.h"

QVector<QString> serial_port_reader::get_name_points()
{
    this->available_Ports->clear();

    foreach (const QSerialPortInfo &portInfo, QSerialPortInfo::availablePorts()) {
        this->available_Ports->append(portInfo.portName());
    }

    return *(this->available_Ports);
}
