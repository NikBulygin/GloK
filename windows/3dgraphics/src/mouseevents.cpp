#include "../widget3d.h"

void widget3d::mousePressEvent(QMouseEvent *pe)
{
    m_pt_Position = pe->pos();
}


void widget3d::mouseMoveEvent(QMouseEvent *pe)
{
    m_x_Rotate += 180 * (GLfloat)(pe->y() - m_pt_Position.y()) / height();
    m_y_Rotate += 180 * (GLfloat)(pe->x() - m_pt_Position.x()) / width();
    update();

    m_pt_Position - pe->pos();

}
