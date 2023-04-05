#include "../item.h"


QVector<float>* item::get_rotate()
{
    return this->m_rotate;
}

float item::get_x_rotate()
{
    return this->m_rotate->at(this->rotate::x);
}

float item::get_y_rotate()
{
    return this->m_rotate->at(this->rotate::y);
}

float item::get_z_rotate()
{
    return this->m_rotate->at(this->rotate::z);
}

void item::set_rotate(QVector<float>* rotate)
{
    if(this->check_input(rotate, this->vec_type::rot))
    {
        this->m_rotate = rotate;
        emit this->was_updated();
    }
    else
    {
        throw std::runtime_error("error set rotate");
    }
}

void item::set_x_rotate(float x)
{
    this->m_rotate->replace(this->rotate::x, x);
    emit this->was_updated();

}

void item::set_y_rotate(float y)
{
    this->m_rotate->replace(this->rotate::y, y);
    emit this->was_updated();
}

void item::set_z_rotate(float z)
{
    this->m_rotate->replace(this->rotate::z, z);
    emit this->was_updated();
}
