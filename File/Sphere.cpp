#include "Sphere.h"
#include <GL/glut.h>


Sphere::Sphere()
{
}

Sphere::Sphere(const float R){
    radius =R;
}


void Sphere:: draw(){
    glPushMatrix();
    glColor3f(color[0],color[1],color[2]);
    applyGLTransform();
    glutSolidSphere(radius,10,10);
    glPopMatrix();
}

void Sphere::draw(float R){
    glPushMatrix();
    glColor3f(color[0],color[1],color[2]);
    applyGLTransform();
    glutSolidSphere(R,10,10);
    glPopMatrix();
}
