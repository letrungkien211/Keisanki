#include<GL/glut.h>
#include "Plane.h"
Plane::Plane(){}

void Plane::draw(){
  switch(drawType){
  case TEXTURE: drawTexture(); break;
  case NOCOLOR: drawNoColor(); break;
  default: drawNormal(); break;
  }
}
void Plane::drawNoColor(){
  glPushMatrix();
  applyGLTransform();
  glPushMatrix();
  glBegin(GL_QUADS);
  glTexCoord2f(0.0, 0.0);
  glVertex3f(-w/2, -0,-h/2);
  glTexCoord2f(tex_width, 0.0);
  glVertex3f(w/2, -0,-h/2);
  glTexCoord2f(tex_width, tex_height);
  glVertex3f(w/2, -0, h/2);
  glTexCoord2f(0, tex_height);
  glVertex3f(-w/2, -0,h/2);
  glEnd();
  glPopMatrix();
  glPopMatrix();
}

void Plane::drawNormal(){
  glPushMatrix();
  applyGLTransform();
  glPushMatrix();
  glColor3f(color[0],color[1],color[2]);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0, 0.0);
  glVertex3f(-w/2, -0,-h/2);
  glTexCoord2f(tex_width, 0.0);
  glVertex3f(w/2, -0,-h/2);
  glTexCoord2f(tex_width, tex_height);
  glVertex3f(w/2, -0, h/2);
  glTexCoord2f(0, tex_height);
  glVertex3f(-w/2, -0,h/2);
  glEnd();
  glPopMatrix();
  glPopMatrix();
}
  

void Plane::drawTexture(){
  glPushMatrix();
  applyGLTransform();
  glEnable(GL_TEXTURE_2D);
  glColor3f(1.0, 1.0, 1.0);
  glBindTexture( GL_TEXTURE_2D, textureId);
  
  //glRotatef(angle[1], 0, 1, 0);
  glNormal3f(normal[0],normal[1], normal[2]);
  
  glPushMatrix(); // +1
  
  glBegin(GL_QUADS);
  glTexCoord2f(0.0, 0.0);
  glVertex3f(-w/2, -0,-h/2);
  glTexCoord2f(tex_width, 0.0);
  glVertex3f(w/2, -0,-h/2);
  glTexCoord2f(tex_width, tex_height);
  glVertex3f(w/2, -0, h/2);
  glTexCoord2f(0, tex_height);
  glVertex3f(-w/2, -0,h/2);
  glEnd();

  glPopMatrix(); // -1
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}
  
void Plane::move(){
  angle[1]+=angularVelocity[1];
}

void Plane::setDrawType(DRAW_TYPE type){
  drawType=type;
}
void Plane::setTexture(float width, float height, int id){
  tex_width =width; tex_height=height;
  textureId=id;
}

void Plane::setSize(float width, float height){
  w=width; h=height;
}

void Plane::setNormal(float x, float y, float z){
  normal.set(x,y,z);
  normal.normalize();
}

float Plane::calculateDistance(){
  distance = position*normal;
  return distance;
}
