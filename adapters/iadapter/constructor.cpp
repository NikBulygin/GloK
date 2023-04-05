#include "../i_adapter.h"

i_adapter::i_adapter()
{
    this->adt_itm = new adapter_item(1);
    this->hash_table = new QHash<QString, int>;
}
