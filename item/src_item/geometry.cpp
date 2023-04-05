#include "../item.h"


QVector<float>* item::get_geometry()
{
    return this->m_geometry;
}
float item::get_width()
{
    return this->m_geometry->at(this->geom::width);
}
float item::get_height()
{
    return this->m_geometry->at(this->geom::height);
}
float item::get_length()
{
    return this->m_geometry->at(this->geom::length);
}
float item::get_scale()
{
    return this->m_geometry->at(this->geom::scale);
}
void item::set_geometry(QVector<float>* geom)
{
    if(this->check_input(geom, this->vec_type::geom))
    {
        this->m_geometry = geom;
        emit this->was_updated();
    }
    else
    {
        throw std::runtime_error("error set geometry");
    }

}
void item::set_width(float w)
{
    this->m_geometry->replace(width, w);
    emit this->was_updated();
}
void item::set_height(float h)
{
    this->m_geometry->replace(this->geom::height, h);
    emit this->was_updated();
}
void item::set_length(float l)
{
    this->m_geometry->replace(this->geom::length, l);
    emit this->was_updated();
}
void item::set_scale(float s)
{
    this->m_geometry->replace(this->geom::scale, s);
    emit this->was_updated();
}
