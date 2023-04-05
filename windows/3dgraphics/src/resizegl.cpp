#include "../widget3d.h"

void widget3d::resizeGL(int w, int h)
{
    glViewport(0,0, (GLint) w, (GLint) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glFrustum(-1.0,1.0,-1.0,1.0,1.0,10.0);
//    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);

    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
}
