#include "../widget3d.h"

widget3d::widget3d(QWidget* parent) : QOpenGLWidget(parent), m_x_Rotate(0), m_y_Rotate(0)
{
    for(int i = 0; i < adp->get_count(); i++)
    {
//        connect(this->adp->get_item(i), &item::was_updated; this, &widget3d::update);
//        connect(this->adp->get_item(i), &item::was_updated, this, &widget3d::resizeGL);

        QObject::connect(adp->get_item(i), &item::was_updated, this, [&](){
                this->update();
            });
    }

    QObject::connect(adp, &adapter_item::updated, this, [&]()
    {
        for(int i = 0; i < adp->get_count(); i++)
        {
    //        connect(this->adp->get_item(i), &item::was_updated; this, &widget3d::update);
    //        connect(this->adp->get_item(i), &item::was_updated, this, &widget3d::resizeGL);

            QObject::connect(adp->get_item(i), &item::was_updated, this, [&](){
                    this->update();
                });
        }

        this->paintGL();

    });

}
