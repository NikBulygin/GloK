#include "../item_widget.h"

void item_widget::update_all()
{
//    QVector<QLineEdit*>* LineEdit_PosXYZZ;
//    QVector<QSlider*>* RotSlidex_XYZ;
//    QVector<QLineEdit*>* RotZero_XYZ;
//    QVector<QLineEdit*>* LineEdit_param;
    if (!manual_modifying)
    {
        for(int i = start; i <= end; i++)
        {
            for(int j = x; j <= z; j++)
            {
                this->LineEdit_PosXYZZ->at(i * z + j + i)->setText(
                            QString::number(
                                j == x ? this->obj->get_start_pos()->x() :
                                         j == y ? this->obj->get_start_pos()->y() :
                                                  this->obj->get_start_pos()->z()
                                ));
            }
        }

        for(int i = width; i <= name; i++)
        {
            if (i != name)
                this->LineEdit_param->at(i)->setText(
                        QString::number(
                            this->obj->get_geometry()->at(i)
                        ));
            else
                this->LineEdit_param->at(i)->setText(
                        this->obj->get_name()
                        );
        }

        for(int i = x; i <=z; i++)
        {
            this->RotSlidex_XYZ->at(i)->setValue(
                        this->obj->get_rotate()->at(i)
                        );
            this->RotZero_XYZ->at(i)->setText(
                        QString::number(
                            this->obj->get_zero_rotate()->at(i)
                            )
                        );
        }
    }
}

