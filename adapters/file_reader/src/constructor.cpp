#include "../file_reader_adapter.h"

file_reader_adapter::file_reader_adapter(QString file_name)
{
    this->file_name = file_name == nullptr ? this->default_file_name : file_name;
}
