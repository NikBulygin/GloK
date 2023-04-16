#include "../adapter_item.h"


//item(QVector3D* sp = nullptr, QString name = "", float w = 0.5, float h = 0.25, float l = 1, float sc = 0.5, float x_r = 0, float y_r = 0, float z_r = 0, item* prnt = nullptr);
//enum Sensor_Area
//{
//    thumb_left = 0,
//    index_main_left = 1,
//    index_second_left = 2,
//    middle_main_left = 3,
//    middle_second_left = 4,
//    ring_main_left = 5,
//    ring_second_left = 6,
//    pinky_main_left = 7,
//    pinky_second_left = 8
//} sa;

adapter_item::adapter_item(int i)
{
    this->items = new QVector<item*>;
}

adapter_item::adapter_item()
{
    this->items = new QVector<item*>;


    this->items->push_back(new item(
                               new QVector3D(0,0,0), // start pos
                               "main", //name
                               4, //w
                               0.25, //h
                               2.5, // l
                               0.8, //s
                               0, //xr
                               0, //xy
                               0, //xz
                               nullptr //parent
                               ));


    this->items->push_back(new item(
                               new QVector3D(-3,0,0), // start pos
                               "thumb_left", //name
                               0.5, //w
                               0.25, //h
                               1, // l
                               0.5, //s
                               0, //xr
                               300, //xy
                               0, //xz
                               nullptr //parent
                               ));

    this->items->push_back(new item(
                               new QVector3D(-1,0,2), // start pos
                               "index_main_left", //name
                               0.5, //w
                               0.25, //h
                               1, // l
                               0.5, //s
                               0, //xr
                               0, //xy
                               0, //xz
                               nullptr //parent
                               ));
    this->items->push_back(new item(
                               nullptr, // start pos
                               "index_second_left", //name
                               0.5, //w
                               0.25, //h
                               1, // l
                               0.5, //s
                               0, //xr
                               0, //xy
                               0, //xz
                               this->get_item(index_main_left) //parent
                               ));


    this->items->push_back(new item(
                               new QVector3D(0,0,2), // start pos
                               "middle_main_left", //name
                               0.5, //w
                               0.25, //h
                               1, // l
                               0.5, //s
                               0, //xr
                               0, //xy
                               0, //xz
                               nullptr //parent
                               ));
    this->items->push_back(new item(
                               nullptr, // start pos
                               "middle_second_left", //name
                               0.5, //w
                               0.25, //h
                               1, // l
                               0.5, //s
                               0, //xr
                               0, //xy
                               0, //xz
                               this->get_item(middle_main_left) //parent
                               ));


    this->items->push_back(new item(
                               new QVector3D(1,0,2), // start pos
                               "ring_main_left", //name
                               0.5, //w
                               0.25, //h
                               1, // l
                               0.5, //s
                               0, //xr
                               0, //xy
                               0, //xz
                               nullptr //parent
                               ));
    this->items->push_back(new item(
                               nullptr, // start pos
                               "ring_second_left", //name
                               0.5, //w
                               0.25, //h
                               1, // l
                               0.5, //s
                               0, //xr
                               0, //xy
                               0, //xz
                               this->get_item(ring_main_left) //parent
                               ));


    this->items->push_back(new item(
                               new QVector3D(2,0,2), // start pos
                               "pinky_main_left", //name
                               0.5, //w
                               0.25, //h
                               1, // l
                               0.5, //s
                               0, //xr
                               0, //xy
                               0, //xz
                               nullptr //parent
                               ));
    this->items->push_back(new item(
                               nullptr, // start pos
                               "pinky_second_left", //name
                               0.5, //w
                               0.25, //h
                               1, // l
                               0.5, //s
                               0, //xr
                               0, //xy
                               0, //xz
                               this->get_item(pinky_main_left) //parent
                               ));

}

void adapter_item::set_items(QVector<item*> *items)
{
    this->items->clear();
    for(int i = 0; i < items->size(); i++)
    {
        this->items->push_back(items->at(i));
    }

    emit updated();
}

//adapter_item::adapter_item(QVector<item>* items) {}
