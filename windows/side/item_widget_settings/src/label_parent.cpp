#include "../item_widget.h"

void item_widget::create_label_parent()
{
    this->Label_parent = new QLabel();
    if (this->obj->get_parent() == nullptr)
    {
        this->Label_parent->setText("null");
    }
    else
    {
        this->Label_parent->setText(this->obj->get_parent()->get_name());
    }
}
