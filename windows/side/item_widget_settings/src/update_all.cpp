#include "../item_widget.h"

void item_widget::update_all()
{

//    QVector<QVector<QSlider*>*>* PosSlider_XYZ;
//    QVector<QVector<QLabel*>*>* PosLabel_XYZ;
//    QVector<QSlider*>* RotSlidex_XYZ;
//    QVector<QLabel*>* RotLabel_XYZ;
//    QVector<QLineEdit*>* LineEdit_param;
//    QLabel* Label_parent;
    QVector3D* start = this->obj->get_start_pos();
    this->PosSlider_XYZ->at(0)->at(0)->setValue(start->x());
    this->PosSlider_XYZ->at(0)->at(1)->setValue(start->y());
    this->PosSlider_XYZ->at(0)->at(2)->setValue(start->z());
    QVector3D* end = this->obj->get_end_pos();
    this->PosSlider_XYZ->at(1)->at(0)->setValue(end->x());
    this->PosSlider_XYZ->at(1)->at(1)->setValue(end->y());
    this->PosSlider_XYZ->at(1)->at(2)->setValue(end->z());

    for (int i = 0; i < 3; i++)
    {
        this->RotSlidex_XYZ->at(i)->setValue(this->obj->get_rotate()->at(i));
    }


//    enum lineedit_geom
//    {
//        width = 0,
//        height = 1,
//        length = 2,
//        scale = 3,
//        name = 4
//    } le;

    for (int i = 0; i <= name; i++)
    {
        if(i == name)
        {
            this->LineEdit_param->at(i)->setText(this->obj->get_name());
        }
        else
        {
            this->LineEdit_param->at(i)->setText(QString::number(this->obj->get_geometry()->at(i)));
        }
    }



}
