#include "../item.h"

void item::calculate_end_pos()
{
    QVector3D vector(0, 0, this->get_length());

    QMatrix4x4 rotationMatrix;
    rotationMatrix.rotate(this->get_x_rotate() - this->get_x_zero_rotate() , 1, 0, 0); // Поворот вокруг оси X
    rotationMatrix.rotate(this->get_y_rotate() - this->get_y_zero_rotate() , 0, 1, 0); // Поворот вокруг оси Y
    rotationMatrix.rotate(this->get_z_rotate() - this->get_z_zero_rotate(), 0, 0, 1); // Поворот вокруг оси Z

    QVector3D rotatedVector = rotationMatrix * vector;
    QVector3D rearCenter = *(this->start_pos) + rotatedVector;
    this->end_pos->setX(rearCenter.x());
    this->end_pos->setY(rearCenter.y());
    this->end_pos->setZ(rearCenter.z());
}
