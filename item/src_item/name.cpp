#include "../item.h"


QString item::get_name()
{
    return this->name;
}

void item::set_name(QString name)
{
    this->name = name;
    emit this->was_updated();
}
