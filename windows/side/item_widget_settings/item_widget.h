#ifndef ITEM_WIDGET_H
#define ITEM_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QVector3D>


#include "../../../item/item.h"

#include <QDebug>

class item_widget: public QWidget
{
    Q_OBJECT
public:
    item_widget(item* related_obj, QWidget* parent = nullptr);

    enum vect_pos
    {
        start = 0,
        end = 1
    };

    enum slider_axis
    {
        x = 0,
        y = 1,
        z = 2,
    };
    enum lineedit_geom
    {
        width = 0,
        height = 1,
        length = 2,
        scale = 3,
        name = 4
    } le;
private:
    const int rot_min = -180;
    const int rot_max = 180;
    bool manual_modifying = false;
protected:
    item* obj;

    QVector<QLineEdit*>* LineEdit_PosXYZZ;
    QVector<QSlider*>* RotSlidex_XYZ;
    QVector<QLineEdit*>* RotZero_XYZ;
    QVector<QLineEdit*>* LineEdit_param;

    item* get_obj()
    {
        return this->obj;
    }

    void set_obj(item* new_obj)
    {
        this->obj = new_obj;
    }

private slots:
    void update_all();
    void manual_updated();

signals:
    void was_updated();

};

#endif // ITEM_WIDGET_H
