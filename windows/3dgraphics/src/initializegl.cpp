#include "../widget3d.h"

void widget3d::initializeGL()
{

    // Создаем контекст OpenGL
    initializeOpenGLFunctions();

    \
    QOpenGLFunctions* pFunc = QOpenGLContext::currentContext()->functions();

    // Устанавливаем свойства источника света
//    GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
//    GLfloat light_ambient[] = {0.2, 0.2, 0.2, 1.0};
//    GLfloat light_diffuse[] = {0.8, 0.8, 0.8, 1.0};
//    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_LIGHTING);
//     glEnable(GL_DEPTH_TEST);

    pFunc->glClearColor(0.0f,0.0f,0.0f, 1.0f);

    pFunc->glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);


//    m_n = createcube(0.5, 0.25, 1);
//    m_n = createcube();
//    m_n = createsphere();

}
