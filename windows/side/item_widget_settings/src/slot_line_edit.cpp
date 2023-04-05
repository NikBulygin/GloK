#include "../item_widget.h"

void item_widget::LineEditing(QString new_value, lineedit_geom type)
{
    //    enum lineedit_geom
    //    {
    //        width = 0,
    //        height = 1,
    //        length = 2,
    //        scale = 3,
    //        name = 4
    //    };

    if (type == name)
    {
        this->obj->set_name(new_value);
    }

    else if(type == width)
    {
        this->obj->set_width(new_value.toFloat());
    }

    else if(type == height)
    {
        this->obj->set_height(new_value.toFloat());
    }

    else if(type == length)
    {
        this->obj->set_length(new_value.toFloat());
    }

    else if(type == scale)
    {
        this->obj->set_scale(new_value.toFloat());
    }
    emit this->was_updated();
    emit this->obj->was_updated();
    if (this->obj->get_parent() != nullptr)
        emit this->obj->get_parent()->was_updated();
}
