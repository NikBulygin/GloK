#include "../bluetooth_reader.h"

QVector<QString> bluetooth_reader::get_name_points()
{
    QVector<QString> result;

    this->scan_result->clear();
    QEventLoop loop;
    this->discovery_agent->start();
    connect(this->discovery_agent, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    for (int i = 0; i < this->scan_result->size(); i++)
    {
        result.append(this->scan_result->at(i).name());
    }
    return result;
}


void bluetooth_reader::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    this->scan_result->append(device);
}
