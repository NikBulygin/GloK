#include "../adapter_item.h"


QVector<item*>* adapter_item::get_items()
{
    return this->items;
}

item* adapter_item::get_item(Sensor_Area index)
{

    return index >=0 && index < this->items->size() ? this->items->at(index) : nullptr;
}

item* adapter_item::get_item(int index)
{
    return index >=0 && index < this->items->size() ? this->items->at(index) : nullptr;
}


int adapter_item::get_count()
{
    return this->items->count();
}
