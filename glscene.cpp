#include "glscene.h"
#include <GL/glut.h>
#include <QMouseEvent>
#include <QPoint>
#include <QKeyEvent>

#include "./File/imageloader.h"

using namespace Qt;

GLScene::GLScene(QWidget *parent) :
    QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()),this, SLOT(updateGL()));
    timer.start(25);

    grabKeyboard();

    fovy = 45; near = 0.01; far = 1000;
    distance =-100;
    mouseButton = NoButton;
    pitch = yaw = 0;

    startTimer(100);  //
}

void GLScene::initializeGL(){
    // Enable
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_FLAT);
    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND); //Enable alpha blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set the blend

    // GL clear
    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
    glClearColor(0.5,0.7,0.7,1);
}

void GLScene::paintGL(){
}

void GLScene::resizeGL(int w, int h){
    windowWidth = w; windowHeight=h;
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovy, (GLfloat)w/(GLfloat)h, near,far);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GLScene::mousePressEvent(QMouseEvent *event){
    mouseButton = event->button();
    lastPos = event->pos();
}

void GLScene::mouseMoveEvent(QMouseEvent *event){
    int x = event->x(), y = event->y();
    int lastX = lastPos.x(), lastY = lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        if( x-lastX==0 && y==lastY ) return;
        yaw -= (GLfloat)( x - lastX ) /10.0;
        pitch -= (GLfloat)( y - lastY ) /10.0;
        updateGL();
    }
    else if(event->buttons() & Qt::RightButton) {
        if( y==lastY ) return;
        if( y < lastY ) distance += (GLfloat)(lastY - y);
        else distance -= (GLfloat)(y - lastY);
        if( -distance < near ) distance = -near;
        if( -distance > far ) distance = -far;
        updateGL();
    }
    lastPos = event->pos();
    mouseButton = event->button();
}

void GLScene::mouseDoubleClickEvent(QMouseEvent *){

}

void GLScene::keyPressEvent(QKeyEvent *){

}

void GLScene::keyReleaseEvent(QKeyEvent *){

}
