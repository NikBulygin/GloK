#include "../item.h"

item::item(QVector3D* sp, QString name, float w, float h, float l, float sc, float x_r, float y_r, float z_r, item* prnt )
{
    this->set_parent(prnt);

    this->m_geometry = new QVector<float>(4);
    this->start_pos = nullptr;
    //
    this->end_pos = new QVector3D(5,5,5);
    this->m_rotate = new QVector<float>(3);

    this->set_start_pos(sp);
    this->set_width(w);
    this->set_height(h);
    this->set_length(l);
    this->set_scale(sc);

    this->set_x_rotate(x);
    this->set_y_rotate(y);
    this->set_z_rotate(z);

    this->name = name;
    this->calculate_end_pos();
    connect(this, &item::was_updated, this, &item::calculate_end_pos);
}

item::item(QVector3D* sp, QString name, QVector<float>* geom , QVector<float>* rot, item* prnt)
{
    this->set_start_pos(sp);
    this->set_geometry(geom);
    this->set_rotate(rot);
    this->set_parent(prnt);

    this->name = name;
}
