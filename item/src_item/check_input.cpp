#include "../item.h"


bool item::check_input(QVector<float>* input, vec_type type)
{
    switch (type) {
    case vec_type::geom:
        if(input->length() == 4)
            return true;
        throw std::overflow_error("Your input for geometry is not equal 4");
        return false;
        break;

    case vec_type::rot:
        if(input->length() == 3)
            return true;

        throw std::overflow_error("Your input for rotate is not equal 3");
        return false;
        break;

    default:
        throw std::overflow_error("Your vec_type is not correct");
        return false;
        break;
    }
}
