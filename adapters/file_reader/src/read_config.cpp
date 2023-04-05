#include "../file_reader_adapter.h"

void file_reader_adapter::read_config()
{
    QFile file(this->file_name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString jsonstr = in.readAll();
    file.close();

    QJsonDocument qjsondoc = QJsonDocument::fromJson(jsonstr.toUtf8());
    this->get_config_data(new QJsonObject(qjsondoc.object()));
}
