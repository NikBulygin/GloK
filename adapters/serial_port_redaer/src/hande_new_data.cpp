#include "../serial_port_reader.h"



void serial_port_reader::handleNewData(QByteArray data)
{
    int index = this->summ_data.indexOf('{');
    if (index != -1) {
        this->summ_data.remove(0, index);
    }

//    this->summ_data = this->summ_data.split(0x1A).at(0)

    qDebug() << this->summ_data;
    QJsonParseError error;
    QJsonDocument qjsondoc = QJsonDocument::fromJson(this->summ_data, &error);
    if(!qjsondoc.isNull())
    {
        qDebug() << "!!!";
        this->summ_data.clear();
        if(qjsondoc.object().contains("config"))
            this->get_config_data(new QJsonObject(qjsondoc.object()));
        if(qjsondoc.object().contains("data") || qjsondoc.object().contains("zero_data"))
            this->get_new_data(new QJsonObject(qjsondoc.object()));
    }
    else {
        qDebug() << summ_data << error.errorString();
        if (error.error == QJsonParseError::GarbageAtEnd)
        {
            this->summ_data.clear();
        }
    }


}

void serial_port_reader::send_data(QByteArray data)
{
    this->serialPort->write(data);
}

void serial_port_reader::readnew_data()
{

    QElapsedTimer timer;
    timer.start();
    while(this->serialPort->bytesAvailable())
    {
        QByteArray new_ch = this->serialPort->read(1);
        qDebug() << new_ch;
        if (new_ch.at(0) == char(0x1B))
        {
            start_read = true;
            continue;
        }
        else if(new_ch.at(0) == char(0x1A))
        {
            start_read = false;
            break;
        }

        if (start_read)
            this->summ_data += new_ch;

    }
    qDebug() << "SUMM:" << this->summ_data;
    if (!start_read)
    {
        emit dataRecieved(this->summ_data);
    }
}
