#include "../item_widget.h"


void item_widget::Slider_modify_pos(float new_value, item_widget::slider_axis axis, item_widget::vect_pos pos)
{
    switch (pos) {
    case 0:
        switch (axis) {
        case 0:
            this->obj->get_start_pos()->setX(new_value);
            break;

        case 1:
            this->obj->get_start_pos()->setY(new_value);
            break;

        case 2:
            this->obj->get_start_pos()->setZ(new_value);
            break;

        default:
            break;
        }
        break;
    case 1:
        switch (axis){
        case 0:
            this->obj->get_end_pos()->setX(new_value);
            break;

        case 1:
            this->obj->get_end_pos()->setY(new_value);
            break;

        case 2:
            this->obj->get_end_pos()->setZ(new_value);
            break;

        default:
            break;
        }
        break;
    default:
        break;
    }


    emit this->was_updated();
    emit this->obj->was_updated();
    if (this->obj->get_parent() != nullptr)
        emit this->obj->get_parent()->was_updated();
}
