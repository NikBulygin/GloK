#include "../widget3d.h"
void widget3d::draw_item_cube(item* itm)
{
    glTranslatef(itm->get_start_pos()->x(),
        itm->get_start_pos()->y(),
        itm->get_start_pos()->z());
    glRotatef(itm->get_x_rotate(), 1.0, 0.0, 0.0);
    glRotatef(itm->get_y_rotate(), 0.0, 1.0, 0.0);
    glRotatef(itm->get_z_rotate(), 0.0, 0.0, 1.0);


//    itm->get_length()
//    enum geom
//    {
//        width = 0,
//        height = 1,
//        length = 2,
//        scale = 3
//    };


    glBegin(GL_QUADS);
//    # передняя
        glColor4f(0,0,1,0.5);
        glVertex3f(-itm->get_width()/2 * itm->get_scale(), -itm->get_height()/2 * itm->get_scale(), itm->get_length()/2);
        glVertex3f(itm->get_width()/2 * itm->get_scale(), -itm->get_height()/2 * itm->get_scale(), itm->get_length()/2);
        glVertex3f(itm->get_width()/2 * itm->get_scale(), itm->get_height()/2 * itm->get_scale(), itm->get_length()/2);
        glVertex3f(-itm->get_width()/2 * itm->get_scale(), itm->get_height()/2 * itm->get_scale(), itm->get_length()/2);
//    # задняя грань
        glVertex3f(-itm->get_width()/2, -itm->get_height()/2, -itm->get_length()/2);
        glVertex3f(itm->get_width()/2, -itm->get_height()/2, -itm->get_length()/2);
        glVertex3f(itm->get_width()/2, itm->get_height()/2, -itm->get_length()/2);
        glVertex3f(-itm->get_width()/2, itm->get_height()/2, -itm->get_length()/2);

        glColor4f(0,1,0,0.5);
//    # верхняя грань
        glVertex3f(-itm->get_width()/2 * itm->get_scale(), itm->get_height()/2 * itm->get_scale(), itm->get_length()/2);
        glVertex3f(itm->get_width()/2 * itm->get_scale(), itm->get_height()/2 * itm->get_scale(), itm->get_length()/2);
        glVertex3f(itm->get_width()/2, itm->get_height()/2, -itm->get_length()/2);
        glVertex3f(-itm->get_width()/2, itm->get_height()/2, -itm->get_length()/2);
//    # нижняя грань
        glVertex3f(-itm->get_width()/2 * itm->get_scale(), -itm->get_height()/2 * itm->get_scale(), itm->get_length()/2);
        glVertex3f(itm->get_width()/2 * itm->get_scale(), -itm->get_height()/2 * itm->get_scale(), itm->get_length()/2);
        glVertex3f(itm->get_width()/2, -itm->get_height()/2, -itm->get_length()/2);
        glVertex3f(-itm->get_width()/2, -itm->get_height()/2, -itm->get_length()/2);

        glColor4f(1,0,0,0.5);
//    # левая грань
        glVertex3f(-itm->get_width()/2 * itm->get_scale(), -itm->get_height()/2 * itm->get_scale(), itm->get_length()/2);
        glVertex3f(-itm->get_width()/2 * itm->get_scale(), itm->get_height()/2 * itm->get_scale(), itm->get_length()/2);
        glVertex3f(-itm->get_width()/2, itm->get_height()/2, -itm->get_length()/2);
        glVertex3f(-itm->get_width()/2, -itm->get_height()/2, -itm->get_length()/2);
//    # правая грань
        glVertex3f(itm->get_width()/2 * itm->get_scale(), -itm->get_height()/2 * itm->get_scale(), itm->get_length()/2);
        glVertex3f(itm->get_width()/2 * itm->get_scale(), itm->get_height()/2 * itm->get_scale(), itm->get_length()/2);
        glVertex3f(itm->get_width()/2, itm->get_height()/2, -itm->get_length()/2);
        glVertex3f(itm->get_width()/2, -itm->get_height()/2, -itm->get_length()/2);
    glEnd();

}
