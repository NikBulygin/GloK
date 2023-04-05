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

protected:
    item* obj;

    QVector<QVector<QSlider*>*>* PosSlider_XYZ;
    QVector<QVector<QLabel*>*>* PosLabel_XYZ;
    QVector<QSlider*>* RotSlidex_XYZ;
    QVector<QLabel*>* RotLabel_XYZ;
    QVector<QLineEdit*>* LineEdit_param;
    QLabel* Label_parent;


    void setlayout();
    void create_lineedits();
    void create_posSLider();
    void create_rotSlider();
    void create_label_parent();
    void create_link_signal();

    item* get_obj()
    {
        return this->obj;
    }

    void set_obj(item* new_obj)
    {
        this->obj = new_obj;
    }

private slots:
    void LineEditing(QString new_value, item_widget::lineedit_geom type);
    void Slider_modify_pos(float new_value, item_widget::slider_axis axis, item_widget::vect_pos pos);
    void Slider_modify_rotate(float new_value, item_widget::slider_axis axis);
    void update_all();

signals:
    void was_updated();

};

#endif // ITEM_WIDGET_H
