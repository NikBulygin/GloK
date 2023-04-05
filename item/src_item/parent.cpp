#include "../item.h"


item* item::get_parent()
{
    return this->parent;
}


void item::set_parent(item* prnt)
{
    if(prnt != nullptr || prnt != 0x0)
    {

        if(this->parent != nullptr)
        {
            disconnect(this->parent, &item::was_updated, this, &item::parents_was_updated);
            disconnect(this, &item::was_updated, this->parent, &item::parents_was_updated);
        }
        this->parent = prnt;
        this->start_pos = this->parent->start_pos;
        if(this->parent != nullptr || this->parent != 0x0)
        {
            connect(this->parent, &item::was_updated, this, &item::parents_was_updated);
    //        connect(this, &item::was_updated, this->parent, &item::parents_was_updated);
        }
    }
}


void item::parents_was_updated()
{
    emit this->was_updated();
}
