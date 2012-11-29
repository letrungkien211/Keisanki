#include "robotgl.h"
#include "./File/Robot.h"
#include <GL/glut.h>
#include <QKeyEvent>

RobotGL::RobotGL(QWidget *parent) :
    GLScene(parent)
{
    robot = new Robot();
}

void RobotGL::initializeGL(){
    GLScene::initializeGL();
    robot->init();
}

void drawLader(int n, int height){
    glPushMatrix();
    glTranslatef(0,10,100);

    for(int i = 0; i<n; ++i){
        if(i)
        glTranslatef(0, height/2, height);
        glColor3f((i%3)/2.0,((i+1)%3)/2.0, ((i+2)%3)/2.0);
        glPushMatrix();
        glScalef(1.0/(i+1), 1, (1.0/(i+1)));
        glutSolidCube(height*(i+1));
        glPopMatrix();
    }
    glPopMatrix();
}


void RobotGL::paintGL(){
    if(this->isHidden())
        return;
    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);

    glRotatef(5,0,1,0);
    glLoadIdentity();

    glTranslatef(0,-100,distance);
    //glRotatef(45,1,0,0);
    glRotatef(90,0,1,0);
    glRotatef(pitch,1,0,0);
    glRotatef(yaw,0,1,0);



    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(-1000, 0, -1000);
    glVertex3f(-1000, 0, 1000);
    glVertex3f(1000, 0, 1000);
    glVertex3f(1000, 0, -1000);
    glEnd();

    drawLader(5,20);


    glPopMatrix();

    glPushMatrix();
    robot->drawHierarchy();
    glPopMatrix();
}

void RobotGL::resizeGL(int w, int h){
    GLScene::resizeGL(w,h);
}

void RobotGL::updateGL(){
    QGLWidget::updateGL();
}

void RobotGL::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_Left:
        robot->rotY(5);
        break;
    case Qt::Key_Right:
        robot->rotY(-5);
        break;
    case Qt::Key_Up:
        robot->moveForward();
        break;
    case Qt::Key_Down:
        robot->moveBackward();
        break;
    default:
        break;
    }
}


void RobotGL::moveForward(const float dis){
    robot->moveForward(dis);
}

void RobotGL::moveBackward(const float dis){
    robot->moveBackward(dis);
}

void RobotGL::turnLeft(const float angle){
    robot->rotY(angle);
}

void RobotGL::turnRight(const float angle){
    robot->rotY(-angle);
}

void RobotGL::climb(const float height){
    robot->climb(height);
}

void RobotGL::descend(const float height){
    robot->descend(height);
}

void RobotGL::identity(){
    robot->reset();
}

void RobotGL::wave(){
    robot->wave();
}
