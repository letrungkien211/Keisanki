#include "Cylinder.h"
#include <GL/glut.h>
#include "Common.h"
#include <cmath>

Cylinder::Cylinder()
{
}
Cylinder::Cylinder(float r, float h){
    radius = r; height = h;
}

void Cylinder::draw(){
    glPushMatrix();
    glColor3f(color[0], color[1], color[2]);
    glBegin(GL_QUADS);

    float s = 2*PI/10.0;

    for(int i=0; i<10; i++){
        glVertex3f(radius*sin(s*i), -height/2, radius*cos(s*i));
        glVertex3f(radius*sin(s*i), height/2, radius*cos(s*i));
        glVertex3f(radius*sin(s*(i+1)), height/2, radius*cos(s*(i+1)));
        glVertex3f(radius*sin(s*(i+1)), -height/2, radius*cos(s*(i+1)));
    }
    glEnd();
    glPopMatrix();
}

void Cylinder::draw(float radius, float height){
    glPushMatrix();
    glColor3f(color[0], color[1], color[2]);
    glBegin(GL_QUADS);

    float s = 2*PI/10.0;

    for(int i=0; i<10; i++){
        glVertex3f(radius*sin(s*i), -height/2, radius*cos(s*i));
        glVertex3f(radius*sin(s*i), height/2, radius*cos(s*i));
        glVertex3f(radius*sin(s*(i+1)), height/2, radius*cos(s*(i+1)));
        glVertex3f(radius*sin(s*(i+1)), -height/2, radius*cos(s*(i+1)));
    }
    glPopMatrix();
}
