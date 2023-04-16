#ifndef MOUSECONTROLLER_H
#define MOUSECONTROLLER_H

#include <QObject>
#include "../../item/item.h"
#include "../../item/adapter_item.h"
#include <QTimer>
#include <QCursor>
#include <QVector3D>
#include <QtMath>

extern adapter_item* adp;

class MouseController : public QObject
{
    Q_OBJECT
public:
    MouseController();

    adapter_item::Sensor_Area get_name_of_sensors()
    {
        return this->name_of_sensors;
    }

    void set_name_of_sensors(adapter_item::Sensor_Area name)
    {
        this->name_of_sensors = name;
    }

    QVector3D get_middle_point()
    {
        return *(this->middle_point);
    }

    void set_middle_point_by_vector(QVector3D new_point)
    {
        this->middle_point = &new_point;
    }

    void calibrate();

private:
    const float save_zone = 0.5;
protected:
    adapter_item::Sensor_Area name_of_sensors;
    QVector3D* middle_point;


public slots:
    void set_middle_point();
    void update();
    void update_adp();

signals:
    void was_updated();
};

#endif // MOUSECONTROLLER_H
