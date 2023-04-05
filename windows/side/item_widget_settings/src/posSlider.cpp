#include "../item_widget.h"

//enum vect_pos
//{
//    start = 0,
//    end = 1
//};

//enum slider_axis
//{
//    x = 0,
//    y = 1,
//    z = 2,
//};

void item_widget::create_posSLider()
{
    this->PosSlider_XYZ = new QVector<QVector<QSlider*>*>;
    this->PosLabel_XYZ = new QVector<QVector<QLabel*>*>;
    for(int i = 0; i < 2; i++)
    {
            this->PosSlider_XYZ->push_back(new QVector<QSlider*>);

            this->PosLabel_XYZ->push_back(new QVector<QLabel*>);
            for (int j = 0; j < 3; j++)
            {
                this->PosSlider_XYZ->at(i)->push_back(new QSlider(Qt::Horizontal));
                this->PosSlider_XYZ->at(i)->at(j)->setRange(-10, 10);
                this->PosLabel_XYZ->at(i)->push_back(new QLabel());

                QObject::connect(this->PosSlider_XYZ->at(i)->at(j), &QSlider::valueChanged, [=](int value){
                    this->PosLabel_XYZ->at(i)->at(j)->setText(QString("%1").arg(QString::number(value).rightJustified(2, '0')));
                    this->Slider_modify_pos(value,
                                            static_cast<slider_axis>(j),
                                            static_cast<vect_pos>(i)
                                            );
                    });
            }
    }

//    this->PosSlider_XYZ->replace(start, new QVector<QSlider*>(3));
//    this->PosSlider_XYZ->replace(end, new QVector<QSlider*>(3));

}
