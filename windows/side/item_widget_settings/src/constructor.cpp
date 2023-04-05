#include "../item_widget.h"

item_widget::item_widget(item* related_obj, QWidget* parent) : QWidget(parent)
{
    this->set_obj(related_obj);

    this->create_lineedits();
    this->create_posSLider();
    this->create_rotSlider();
    this->create_label_parent();
    this->create_link_signal();
    this->setlayout();
    this->update_all();
}


