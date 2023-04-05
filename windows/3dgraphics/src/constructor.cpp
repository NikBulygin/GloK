#include "../widget3d.h"

widget3d::widget3d(adapter_item* adp ,QWidget* parent) : QOpenGLWidget(parent), m_x_Rotate(0), m_y_Rotate(0)
{
    this->adp = adp;

    for(int i = 0; i < this->adp->get_count(); i++)
    {
//        connect(this->adp->get_item(i), &item::was_updated; this, &widget3d::update);
//        connect(this->adp->get_item(i), &item::was_updated, this, &widget3d::resizeGL);

        QObject::connect(this->adp->get_item(i), &item::was_updated, this, [&](){
                this->update();
            });
    }

}
