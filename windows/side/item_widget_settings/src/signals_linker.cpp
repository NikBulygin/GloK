#include "../item_widget.h"

void item_widget::create_link_signal()
{
    connect(obj, &item::was_updated , this, &item_widget::update_all);
}
