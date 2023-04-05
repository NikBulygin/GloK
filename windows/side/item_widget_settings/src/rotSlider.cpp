#include "../item_widget.h"

void item_widget::create_rotSlider()
{
    this->RotSlidex_XYZ = new QVector<QSlider*>;
    this->RotLabel_XYZ = new QVector<QLabel*>;
    for (int i = 0; i <= 3; i++)
    {
        this->RotSlidex_XYZ->push_back(new QSlider(Qt::Horizontal));
        this->RotLabel_XYZ->push_back(new QLabel());
        this->RotSlidex_XYZ->at(i)->setRange(0, 360);


        QObject::connect(this->RotSlidex_XYZ->at(i), &QSlider::valueChanged, [=](int value){
            this->RotLabel_XYZ->at(i)->setText(QString("%1").arg(QString::number(value).rightJustified(3, '0')));
            this->Slider_modify_rotate(value,
                                       static_cast<slider_axis>(i));
            });
        this->RotSlidex_XYZ->at(i)->setValue(360);
        this->RotSlidex_XYZ->at(i)->setValue(0);
    }


}
