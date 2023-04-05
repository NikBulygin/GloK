#include "../file_reader_adapter.h"

QString file_reader_adapter::get_file_name()
{
    return this->file_name;
}

void file_reader_adapter::change_file(QString file_name)
{
    this->file_name = file_name;
}
