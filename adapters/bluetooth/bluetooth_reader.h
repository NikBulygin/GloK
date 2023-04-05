#ifndef BLUETOOTH_READER_H
#define BLUETOOTH_READER_H



#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>
#include <QEventLoop>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "../i_adapter.h"

class bluetooth_reader : public i_adapter
{
private:
    QBluetoothDeviceDiscoveryAgent* discovery_agent;
    QVector<QBluetoothDeviceInfo>* scan_result;
private slots:
    void deviceDiscovered (const QBluetoothDeviceInfo& device);
public:
    bluetooth_reader();

    void connect_to_point(int i, QString password) override;
    QVector<QString> get_name_points() override;
};
#endif // BLUETOOTH_READER_H
