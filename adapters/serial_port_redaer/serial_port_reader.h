#ifndef SERIAL_PORT_READER_H
#define SERIAL_PORT_READER_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QElapsedTimer>
#include <QTimer>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "../i_adapter.h"


class serial_port_reader : public i_adapter
{
    Q_OBJECT
public:
    serial_port_reader();
    void set_baudrate(QSerialPort::BaudRate baudrate)
    {
        this->baudrate = baudrate;
    }
    int get_baudrate()
    {
        return this->baudrate;
    }

    QVector<QString> get_name_points() override;
    void connect_to_point(int i, QString password = nullptr) override;
    void disconnect_from_point();
    bool is_connected_to_point();
private:
    bool start_read = false;

    QByteArray summ_data;
    int baudrate;
    QSerialPort* serialPort;
    QVector<QString>* available_Ports;

signals:
    void dataRecieved(QByteArray data);

private slots:
    void readnew_data();
    void handleNewData(QByteArray data);
public slots:
    void send_data(QByteArray data);
};


#endif // SERIAL_PORT_READER_H
