#ifndef ADAPTER_ITEM_H
#define ADAPTER_ITEM_H
#include "item.h"
#include <QVector3D>

class adapter_item : public QObject
{
    Q_OBJECT
protected:
    QVector<item*>* items;

public:
    enum Sensor_Area
    {
        main = -1,
        thumb_left,
        index_main_left,
        index_second_left,
        middle_main_left,
        middle_second_left,
        ring_main_left,
        ring_second_left,
        pinky_main_left,
        pinky_second_left
    } sa;


    adapter_item();
    adapter_item(int i);
    void set_items(QVector<item*>* items);

    QVector<item*>* get_items();
    item* get_item(Sensor_Area index);
    item* get_item(int index);

    void delete_item(Sensor_Area index);
    void delete_item(int index);

    int get_count();

signals:
    void updated();
};

#endif // ADAPTER_ITEM_H
