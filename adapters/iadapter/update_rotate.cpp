#include "../i_adapter.h"

void i_adapter::update_rotate(adapter_item::Sensor_Area index,
        float x, float y, float z, bool is_zero)
{
    if(is_zero)
    {
        this->adt_itm->get_item(index)->set_x_zero_rotate(x);
        this->adt_itm->get_item(index)->set_y_zero_rotate(y);
        this->adt_itm->get_item(index)->set_z_zero_rotate(z);
    }
    else
    {
        this->adt_itm->get_item(index)->set_x_rotate(x);
        this->adt_itm->get_item(index)->set_y_rotate(y);
        this->adt_itm->get_item(index)->set_z_rotate(z);
    }
}
