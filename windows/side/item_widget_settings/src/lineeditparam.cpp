#include "../item_widget.h"

void item_widget::create_lineedits()
{


//    QVector<QLineEdit*> LineEdit_param;

//    enum lineedit_geom
//    {
//        width = 0,
//        height = 1,
//        length = 2,
//        scale = 3,
//        name = 4
//    };

    this->LineEdit_param = new QVector<QLineEdit*>;
    for(int i = 0; i < 5; i++)
    {
        this->LineEdit_param->push_back( new QLineEdit());

        QObject::connect(this->LineEdit_param->at(i), &QLineEdit::editingFinished, [=]()
        {
           this->LineEditing(this->LineEdit_param->at(i)->text(), static_cast<lineedit_geom>(i));
        });

    }
    this->LineEdit_param->at(width)->setText(QString::number(this->obj->get_width()));
    this->LineEdit_param->at(height)->setText(QString::number(this->obj->get_height()));
    this->LineEdit_param->at(length)->setText(QString::number(this->obj->get_length()));
    this->LineEdit_param->at(scale)->setText(QString::number(this->obj->get_scale()));
    this->LineEdit_param->at(name)->setText(this->obj->get_name());


//    this->LineEdit_param->at(width)->setText(QString::number(123));
//    this->LineEdit_param->at(height)->setText(QString::number(234));
//    this->LineEdit_param->at(length)->setText(QString::number(345));
//    this->LineEdit_param->at(scale)->setText(QString::number(456));
//    this->LineEdit_param->at(name)->setText(this->obj->get_name());
}
