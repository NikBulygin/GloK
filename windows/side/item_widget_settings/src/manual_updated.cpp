#include "../item_widget.h"

void item_widget::manual_updated()
{
//    QVector<QLineEdit*>* LineEdit_PosXYZZ;
//    QVector<QSlider*>* RotSlidex_XYZ;
//    QVector<QLineEdit*>* RotZero_XYZ;
//    QVector<QLineEdit*>* LineEdit_param;
    manual_modifying =true;
    qDebug() << "manual editing)";
    this->obj->set_start_pos(new QVector3D(
                                 this->LineEdit_PosXYZZ->at(start * z + x)->text().toDouble(),
                                 this->LineEdit_PosXYZZ->at(start * z + y)->text().toDouble(),
                                 this->LineEdit_PosXYZZ->at(start * z + z)->text().toDouble()
                                 ));

    this->obj->set_width(this->LineEdit_param->at(width)->text().toDouble());
    this->obj->set_length(this->LineEdit_param->at(length)->text().toDouble());
    this->obj->set_height(this->LineEdit_param->at(height)->text().toDouble());
    this->obj->set_scale(this->LineEdit_param->at(scale)->text().toDouble());

    this->obj->set_x_rotate(this->RotSlidex_XYZ->at(x)->value());
    this->obj->set_y_rotate(this->RotSlidex_XYZ->at(y)->value());
    this->obj->set_z_rotate(this->RotSlidex_XYZ->at(z)->value());


    this->obj->set_x_zero_rotate(this->RotZero_XYZ->at(x)->text().toDouble());
    this->obj->set_x_zero_rotate(this->RotZero_XYZ->at(y)->text().toDouble());
    this->obj->set_x_zero_rotate(this->RotZero_XYZ->at(z)->text().toDouble());
    manual_modifying = false;
}
