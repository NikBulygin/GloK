#include "../item.h"

void item::draw()
{/*
    GLuint n = glGenLists(1);
    glNewList(n, GL_COMPILE);
    glEndList () ;*/
//    enum geom
//    {
//        width = 0,
//        height = 1,
//        length = 2,
//        scale = 3
//    };
//    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glTranslatef(this->get_start_pos()->x(),
        this->get_start_pos()->y(),
        this->get_start_pos()->z());

//    this->get_length()

    glBegin(GL_QUADS);
//    # передняя
        glColor4f(0,0,1,0.5);
        glVertex3f(-this->get_width()/2 * this->get_scale(), -this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2 * this->get_scale(), -this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2 * this->get_scale(), this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(-this->get_width()/2 * this->get_scale(), this->get_height()/2 * this->get_scale(), this->get_length()/2);
//    # задняя грань
        glVertex3f(-this->get_width()/2, -this->get_height()/2, -this->get_length()/2);
        glVertex3f(this->get_width()/2, -this->get_height()/2, -this->get_length()/2);
        glVertex3f(this->get_width()/2, this->get_height()/2, -this->get_length()/2);
        glVertex3f(-this->get_width()/2, this->get_height()/2, -this->get_length()/2);

        glColor4f(0,1,0,0.5);
//    # верхняя грань
        glVertex3f(-this->get_width()/2 * this->get_scale(), this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2 * this->get_scale(), this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2, this->get_height()/2, -this->get_length()/2);
        glVertex3f(-this->get_width()/2, this->get_height()/2, -this->get_length()/2);
//    # нижняя грань
        glVertex3f(-this->get_width()/2 * this->get_scale(), -this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2 * this->get_scale(), -this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2, -this->get_height()/2, -this->get_length()/2);
        glVertex3f(-this->get_width()/2, -this->get_height()/2, -this->get_length()/2);

        glColor4f(1,0,0,0.5);
//    # левая грань
        glVertex3f(-this->get_width()/2 * this->get_scale(), -this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(-this->get_width()/2 * this->get_scale(), this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(-this->get_width()/2, this->get_height()/2, -this->get_length()/2);
        glVertex3f(-this->get_width()/2, -this->get_height()/2, -this->get_length()/2);
//    # правая грань
        glVertex3f(this->get_width()/2 * this->get_scale(), -this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2 * this->get_scale(), this->get_height()/2 * this->get_scale(), this->get_length()/2);
        glVertex3f(this->get_width()/2, this->get_height()/2, -this->get_length()/2);
        glVertex3f(this->get_width()/2, -this->get_height()/2, -this->get_length()/2);
    glEnd();

}
