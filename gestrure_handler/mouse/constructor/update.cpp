#include "../MouseController.h"

void MouseController::update_adp()
{
    QObject::connect(adp->get_item(name_of_sensors), &item::was_updated,
                                   this, &MouseController::update);
}

void MouseController::update()
{
    emit this->was_updated();
    float x = QCursor::pos().x(),
            y = QCursor::pos().y(),
            delta_x = 0,
            delta_y = 0;

    float distance = qSqrt(
                qPow(adp->get_item(name_of_sensors)->get_end_pos()->x() - this->middle_point->x(), 2) +
                qPow(adp->get_item(name_of_sensors)->get_end_pos()->y() - this->middle_point->y(), 2));

    if (distance < save_zone) {
        delta_x = 0;
        delta_y = 0;
    }

    if (adp->get_item(name_of_sensors)->get_end_pos()->y() < this->middle_point->y() - save_zone) {
        delta_y = 1;
    } else if (adp->get_item(name_of_sensors)->get_end_pos()->y() > this->middle_point->y() + save_zone) {
        delta_y = -1;
    }

    if (adp->get_item(name_of_sensors)->get_end_pos()->x() < this->middle_point->x() - save_zone) {
       delta_x = -1;
    } else if (adp->get_item(name_of_sensors)->get_end_pos()->x() > this->middle_point->x() + save_zone) {
        delta_x = 1;
    }
//    QCursor::setPos(
//                x + delta_x,
//                y + delta_y);
}



void MouseController::set_middle_point()
{
//    this->middle_point = adp->get_item(name_of_sensors)->get_end_pos();
    this->middle_point->setX(adp->get_item(name_of_sensors)->get_end_pos()->x());
    this->middle_point->setY(adp->get_item(name_of_sensors)->get_end_pos()->y());
    this->middle_point->setZ(adp->get_item(name_of_sensors)->get_end_pos()->z());
    emit this->was_updated();
}
