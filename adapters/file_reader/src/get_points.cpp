#include "../file_reader_adapter.h"


QVector<QString> file_reader_adapter::get_name_points()
{
    QVector<QString> result;
    QDir directory(this->file_name);
    QStringList files = directory.entryList(QDir::Files);
    for(int i = 0; i < files.size(); i++)
    {
        result.append(directory.absoluteFilePath(files.at(i)));
    }
    return result;
}
