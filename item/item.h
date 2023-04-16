#ifndef ITEM_H
#define ITEM_H

#include <QOpenGLFunctions>
#include <QVector3D>
#include <QObject>
#include <cmath>
#include <QMatrix4x4>

class item : public QObject, protected QOpenGLFunctions
{
    Q_OBJECT
protected:
    QVector<float>* m_geometry; //4

    QVector3D* start_pos = nullptr;
    QVector3D* end_pos = nullptr;

    QVector<float>* m_rotate; //3
    QVector<float>* m_zero_rotate;

    QString name;
    item* parent = nullptr;
private:
    enum vec_type
    {
        geom = 0,
        rot = 1
    };

//    bool check_input(QVector3D* input);
    bool check_input(QVector<float>* input, vec_type type);

public:
    enum rotate
    {
        x = 0,
        y = 1,
        z = 2,
        s = 3
    };

    enum geom
    {
        width = 0,
        height = 1,
        length = 2,
        scale = 3
    };

    item(QVector3D* sp = nullptr, QString name = "", float w = 0.5, float h = 0.25, float l = 1, float sc = 0.5, float x_r = 0, float y_r = 0, float z_r = 0, item* prnt = nullptr);
    item(QVector3D* sp = nullptr, QString name = "", QVector<float>* geom = nullptr, QVector<float>* rot = nullptr, item* prnt = nullptr);


    QVector3D* get_start_pos();
    QVector3D* get_end_pos();
    void set_start_pos(QVector3D* sp);

    QVector<float>* get_geometry();
    float get_width();
    float get_height();
    float get_length();
    float get_scale();
    void set_geometry(QVector<float>* geom);
    void set_width(float w);
    void set_height(float h);
    void set_length(float l);
    void set_scale(float s);

    QVector<float>* get_rotate();
    float get_x_rotate();
    float get_y_rotate();
    float get_z_rotate();
    void set_rotate(QVector<float>* rotate);
    void set_x_rotate(float x);
    void set_y_rotate(float y);
    void set_z_rotate(float z);

    QVector<float>* get_zero_rotate();
    float get_x_zero_rotate();
    float get_y_zero_rotate();
    float get_z_zero_rotate();
    void set_zero_rotate(QVector<float>* rotate);
    void set_x_zero_rotate(float x);
    void set_y_zero_rotate(float y);
    void set_z_zero_rotate(float z);

    item* get_parent();
    void set_parent(item* prnt);

    QString get_name();
    void set_name(QString name);

private slots:
    void draw();
    void parents_was_updated();
    void calculate_end_pos();

signals:
    void was_updated();
};

#endif // ITEM_H
