#include "../bluetooth_reader.h"

bluetooth_reader::bluetooth_reader()
{
    this->scan_result = new QVector<QBluetoothDeviceInfo>;
    this->discovery_agent = new QBluetoothDeviceDiscoveryAgent;
//    connect(this->discovery_agent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this, SLOT(deviceDiscovered(QBluetoothDeviceInfo&)));
    connect(this->discovery_agent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &bluetooth_reader::deviceDiscovered);

}
