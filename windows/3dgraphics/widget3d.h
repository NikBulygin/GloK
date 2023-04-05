#ifndef WIDGET3D_H
#define WIDGET3D_H

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMouseEvent>
#include <QTime>

#include "../../item/adapter_item.h"
#include "../../item/item.h"

class widget3d : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    widget3d(adapter_item* adp ,QWidget* parent = nullptr);

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent(QMouseEvent* pe);
//    GLuint createcube(GLfloat w = 1.0f, GLfloat h = 1.0f, GLfloat l = 1.0f);
    void draw_item_cube(item* itm);

private:
    GLuint m_n; //display list
    GLfloat m_y_Rotate;
    GLfloat m_x_Rotate;
    QPoint m_pt_Position;
    adapter_item* adp;
};

#endif // 3DWIDGET_H
