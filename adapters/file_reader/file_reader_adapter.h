#ifndef FILE_READER_ADAPTER_H
#define FILE_READER_ADAPTER_H

#include <QFile>
#include <QTextStream>
#include <QDir>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "../i_adapter.h"

class file_reader_adapter : public i_adapter
{
private:
    const QString default_file_name = "example_data/example_input_config.json";
    QString file_name = default_file_name;

public:
    file_reader_adapter(QString file_name = nullptr);
    void read_config();
    void read_data();

    void connect_to_point(int i, QString password) override;
    QVector<QString> get_name_points() override;

    QString get_file_name();
    void change_file(QString file_name);
};

#endif // FILE_READER_ADAPTER_H
