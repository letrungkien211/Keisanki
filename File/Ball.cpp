#include "Ball.h"
#include <GL/glut.h>

Ball::Ball(){}

float Ball::getRadius(){
  return radius;
}
void Ball::setRadius(float r){
  radius=r;
}
void Ball::draw(){
  glColor3f(color[0],color[1],color[2]);
  
  glPushMatrix();
  glTranslatef(position[0], position[1], position[2]);
  glutSolidSphere(radius,10,10);
  glPopMatrix();
}
void Ball::move(){
  position+=velocity;
}
