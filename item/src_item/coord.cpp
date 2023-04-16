#include "../item.h"

QVector3D* item::get_start_pos()
{
    return this->start_pos;
}


QVector3D* item::get_end_pos()
{
    return this->end_pos;
}

void item::set_start_pos(QVector3D* sp)
{
    if(this->parent != nullptr)
    {
        this->start_pos = this->parent->get_end_pos();
    }
    else
    {
        if(sp == nullptr)
        {
            this->start_pos = new QVector3D(0,0,0);
        }
        else
        {
            delete this->start_pos;
            this->start_pos = sp;
        }
    }

    emit this->was_updated();
}
