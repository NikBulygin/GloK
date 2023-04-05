#include "../item_widget.h"

void item_widget::Slider_modify_rotate(float new_value, slider_axis axis)
{
    switch (axis) {
    case 0:
        this->obj->set_x_rotate(new_value);
        break;
    case 1:
        this->obj->set_y_rotate(new_value);
        break;
    case 2:
        this->obj->set_z_rotate(new_value);
        break;
    default:
        break;
    }

    emit this->was_updated();
    emit this->obj->was_updated();
}
