#include "../MouseController.h"

MouseController::MouseController()
{
    QObject::connect(adp, &adapter_item::updated, this, &MouseController::update_adp);
    this->middle_point = new QVector3D(0,0,0);
}
