#include "sierpinsky3dgl.h"
#include "./File/Sierpinsky3D.h"
#include <GL/glut.h>

Sierpinsky3DGL::Sierpinsky3DGL(QWidget *parent) :
    GLScene(parent)
{
    sier = new Sierpinsky3D();
}

void Sierpinsky3DGL::initializeGL(){
    GLScene::initializeGL();
    sier->init();
}

void Sierpinsky3DGL::paintGL(){
    if(this->isHidden())
        return;
    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2,0.2,0.2,0);

    glLoadIdentity();

    glTranslatef(0,0,distance);
    glRotatef(pitch,1,0,0);
    glRotatef(yaw,0,1,0);

    glPushMatrix();

    glColor3f(1,0,0);
    glutWireTeapot(0.6);
    sier->draw();

    glPopMatrix();

    //glutSwapBuffers();
}

void Sierpinsky3DGL::resizeGL(int w, int h){
    GLScene::resizeGL(w,h);
}

void Sierpinsky3DGL::updateGL(){
    sier->update(16);
    QGLWidget::updateGL();
}
