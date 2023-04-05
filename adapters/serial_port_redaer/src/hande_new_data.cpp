#include "../serial_port_reader.h"

void serial_port_reader::handleNewData(QByteArray data)
{
//    qDebug() << summ_data;
    this->summ_data  += data;
    QJsonParseError error;
    QJsonDocument qjsondoc = QJsonDocument::fromJson(summ_data, &error);
    if(!qjsondoc.isNull())
    {
        qDebug() << "!!!";
        summ_data.clear();
        this->get_config_data(new QJsonObject(qjsondoc.object()));
    }
    {
        qDebug() << summ_data << error.errorString();
    }


}

void serial_port_reader::send_data(QByteArray data)
{
    this->serialPort->write(data);
}

void serial_port_reader::readnew_data()
{
    QByteArray new_data;
    while (!this->serialPort->atEnd()) {
        new_data += this->serialPort->readLine();
    }
    emit dataRecieved(new_data);
}
