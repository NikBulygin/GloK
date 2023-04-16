#include "../item.h"

void item::draw()
{
    glLoadIdentity();
    glTranslatef(this->get_start_pos()->x(),
        this->get_start_pos()->y(),
        this->get_start_pos()->z());
    glBegin(GL_QUADS);
//    # face
        glColor4f(0,0,1,0.5);
        glVertex3f(-this->get_width()/2 * this->get_scale(), -this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2 * this->get_scale(), -this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2 * this->get_scale(), this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(-this->get_width()/2 * this->get_scale(), this->get_height()/2 * this->get_scale(), this->get_length()/2);
//    # back
        glVertex3f(-this->get_width()/2, -this->get_height()/2, -this->get_length()/2);
        glVertex3f(this->get_width()/2, -this->get_height()/2, -this->get_length()/2);
        glVertex3f(this->get_width()/2, this->get_height()/2, -this->get_length()/2);
        glVertex3f(-this->get_width()/2, this->get_height()/2, -this->get_length()/2);

        glColor4f(0,1,0,0.5);
//    # top
        glVertex3f(-this->get_width()/2 * this->get_scale(), this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2 * this->get_scale(), this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2, this->get_height()/2, -this->get_length()/2);
        glVertex3f(-this->get_width()/2, this->get_height()/2, -this->get_length()/2);
//    # bottom
        glVertex3f(-this->get_width()/2 * this->get_scale(), -this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2 * this->get_scale(), -this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2, -this->get_height()/2, -this->get_length()/2);
        glVertex3f(-this->get_width()/2, -this->get_height()/2, -this->get_length()/2);

        glColor4f(1,0,0,0.5);
//    # left
        glVertex3f(-this->get_width()/2 * this->get_scale(), -this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(-this->get_width()/2 * this->get_scale(), this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(-this->get_width()/2, this->get_height()/2, -this->get_length()/2);
        glVertex3f(-this->get_width()/2, -this->get_height()/2, -this->get_length()/2);
//    # right
        glVertex3f(this->get_width()/2 * this->get_scale(), -this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2 * this->get_scale(), this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2, this->get_height()/2, -this->get_length()/2);
        glVertex3f(this->get_width()/2, -this->get_height()/2, -this->get_length()/2);
    glEnd();

}
