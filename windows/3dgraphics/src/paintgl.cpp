#include "../widget3d.h"

void widget3d::paintGL()
{
    qDebug() << "redraw" << QTime::currentTime();
   glClear(GL_COLOR_BUFFER_BIT || GL_DEPTH_BUFFER_BIT);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
//   glTranslatef(0.0, 0.0, -3.0);
//   glRotatef(m_x_Rotate, 1.0,0.0,0.0);
//   glRotatef(m_y_Rotate, 0.0,1.0,0.0);

//   glCallList(m_n);
//   glLoadIdentity();

//   glTranslatef(1.0, 0.0, -3.0);
//   glRotatef(m_x_Rotate, 1.0,0.0,0.0);
//   glRotatef(m_y_Rotate, 0.0,1.0,0.0);

//   glCallList(m_n);

   for(int i = 0; i < this->adp->get_count(); i++)
   {

//        glRotatef(this->adp->get_item(i)->get_x_rotate(), 1.0, 0.0, 0.0);
//        glRotatef(this->adp->get_item(i)->get_y_rotate(), 0.0, 1.0, 0.0);
//        glRotatef(this->adp->get_item(i)->get_z_rotate(), 0.0, 0.0, 1.0);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glRotatef(m_x_Rotate, 1.0,0.0,0.0);
        glRotatef(m_y_Rotate, 0.0,1.0,0.0);
        draw_item_cube(this->adp->get_item(i));
//        createcube(0.5, 0.25, 1);
//        this->adp->get_item(i)->draw();
   }
}
