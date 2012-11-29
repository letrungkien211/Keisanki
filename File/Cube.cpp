#include <GL/glut.h>
#include <algorithm>
#include <vector>
#include <iostream>

#include "Cube.h"
#include "Affine.h"
#include "Vec3f.h"

Cube::Cube(){
  w=h=d=1;
  drawType = NORMAL;
}
Cube::Cube(float w, float h, float d){
  this->w=w; this->h=h; this->d=d;
}
Cube::  ~Cube(){}
void Cube:: setSize(float w, float h, float d){
  Plane::setSize(w,h);
  this->d=d;
}

void Cube::draw(){
  switch(drawType){
  case TEXTURE: drawTexture(); break;
  case NOCOLOR: drawNoColor(); break;
  default: drawNormal(); 
    break;
  }
}
void Cube:: drawNormal(){
  glColor4f(color[0], color[1], color[2],1);
  glPushMatrix();
  glBegin(GL_QUADS);
  //Top face
  //glColor3f(1.0f, 1.0f, 0.0f);
  glNormal3f(0.0, 1.0f, 0.0f);
  glVertex3f(-w / 2, h / 2, -d / 2);
  glVertex3f(-w / 2, h / 2, d / 2);
  glVertex3f(w / 2, h / 2, d / 2);
  glVertex3f(w / 2, h / 2, -d / 2);
  //Bottom face
  //glColor3f(1.0f, 0.0f, 1.0f);
  glNormal3f(0.0, -1.0f, 0.0f);
  glVertex3f(-w / 2, -h / 2, -d / 2);
  glVertex3f(w / 2, -h / 2, -d / 2);
  glVertex3f(w / 2, -h / 2, d / 2);
  glVertex3f(-w / 2, -h / 2, d / 2);
  //Left face
  glNormal3f(-1.0, 0.0f, 0.0f);
  //glColor3f(0.0f, 1.0f, 1.0f);
  glVertex3f(-w / 2, -h / 2, -d / 2);
  glVertex3f(-w / 2, -h / 2, d / 2);
  //glColor3f(0.0f, 0.0f, 1.0f);
  glVertex3f(-w / 2, h / 2, d / 2);
  glVertex3f(-w / 2, h / 2, -d / 2);
  //Right face
  glNormal3f(1.0, 0.0f, 0.0f);
  //glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(w / 2, -h / 2, -d / 2);
  glVertex3f(w / 2, h / 2, -d / 2);
  //glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(w / 2, h / 2, d / 2);
  glVertex3f(w / 2, -h / 2, d / 2);
  //Front face
  glNormal3f(0.0, 0.0f, 1.0f);
  //glColor3f(1.0f, 0.5f, 0.0f);
  glVertex3f(-w / 2, -h / 2, d / 2);
  glVertex3f(w / 2, -h / 2, d / 2);
  glVertex3f(w / 2 , h / 2, d / 2);
  glVertex3f(-w / 2, h / 2, d / 2);

  //Back face
  glNormal3f(0.0, 0.0f, -1.0f);
  //glColor3f(1.0f, 0.5f, 0.3f);
  glVertex3f(-w / 2, -h / 2, -d / 2);
  glVertex3f(-w / 2, h / 2, -d / 2);
  glVertex3f(w / 2, h / 2, -d / 2);
  glVertex3f(w / 2, -h / 2, -d / 2);

  glEnd();
  glPopMatrix();
}

void Cube:: drawTexture(){
  glBegin(GL_QUADS);
  //Top face
  glColor3f(1.0f, 1.0f, 0.0f);
  glNormal3f(0.0, 1.0f, 0.0f);
  glVertex3f(-w / 2, h / 2, -d / 2);
  glVertex3f(-w / 2, h / 2, d / 2);
  glVertex3f(w / 2, h / 2, d / 2);
  glVertex3f(w / 2, h / 2, -d / 2);
	
  //Bottom face
  glColor3f(1.0f, 0.0f, 1.0f);
  glNormal3f(0.0, -1.0f, 0.0f);
  glVertex3f(-w / 2, -h / 2, -d / 2);
  glVertex3f(w / 2, -h / 2, -d / 2);
  glVertex3f(w / 2, -h / 2, d / 2);
  glVertex3f(-w / 2, -h / 2, d / 2);
  
  //Left face
  glNormal3f(-1.0, 0.0f, 0.0f);
  glColor3f(0.0f, 1.0f, 1.0f);
  glVertex3f(-w / 2, -h / 2, -d / 2);
  glVertex3f(-w / 2, -h / 2, d / 2);
  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex3f(-w / 2, h / 2, d / 2);
  glVertex3f(-w / 2, h / 2, -d / 2);
	
  //Right face
  glNormal3f(1.0, 0.0f, 0.0f);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(w / 2, -h / 2, -d / 2);
  glVertex3f(w / 2, h / 2, -d / 2);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(w / 2, h / 2, d / 2);
  glVertex3f(w / 2, -h / 2, d / 2);
	
  glEnd();
	
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,textureId);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glColor3f(1.0f, 1.0f, 1.0f);
  glBegin(GL_QUADS);
	
  //Front face
  glNormal3f(0.0, 0.0f, 1.0f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-w / 2, -h / 2, d / 2);
  glTexCoord2f(tex_width, 0.0f);
  glVertex3f(w / 2, -h / 2, d / 2);
  glTexCoord2f(tex_width, tex_height);
  glVertex3f(w / 2 , h / 2, d / 2);
  glTexCoord2f(0.0f, tex_height);
  glVertex3f(-w / 2, h / 2, d / 2);
	
  //Back face
  glNormal3f(0.0, 0.0f, -1.0f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-w / 2, -h / 2, -d / 2);
  glTexCoord2f(0.0f, tex_height);
  glVertex3f(-w / 2, h / 2, -d / 2);
  glTexCoord2f(tex_width, tex_height);
  glVertex3f(w / 2, h / 2, -d / 2);
  glTexCoord2f(tex_width, 0.0f);
  glVertex3f(w / 2, -h / 2, -d / 2);
	
  glEnd();
  glDisable(GL_TEXTURE_2D);
}
void Cube:: drawNoColor(){
  glPushMatrix();
  glBegin(GL_QUADS);
  //Top face

  glNormal3f(0.0, 1.0f, 0.0f);
  glVertex3f(-w / 2, h / 2, -d / 2);
  glVertex3f(-w / 2, h / 2, d / 2);
  glVertex3f(w / 2, h / 2, d / 2);
  glVertex3f(w / 2, h / 2, -d / 2);
  //Bottom face

  glNormal3f(0.0, -1.0f, 0.0f);
  glVertex3f(-w / 2, -h / 2, -d / 2);
  glVertex3f(w / 2, -h / 2, -d / 2);
  glVertex3f(w / 2, -h / 2, d / 2);
  glVertex3f(-w / 2, -h / 2, d / 2);
  //Left face
  glNormal3f(-1.0, 0.0f, 0.0f);

  glVertex3f(-w / 2, -h / 2, -d / 2);
  glVertex3f(-w / 2, -h / 2, d / 2);

  glVertex3f(-w / 2, h / 2, d / 2);
  glVertex3f(-w / 2, h / 2, -d / 2);
  //Right face
  glNormal3f(1.0, 0.0f, 0.0f);

  glVertex3f(w / 2, -h / 2, -d / 2);
  glVertex3f(w / 2, h / 2, -d / 2);

  glVertex3f(w / 2, h / 2, d / 2);
  glVertex3f(w / 2, -h / 2, d / 2);
  //Front face
  
  glVertex3f(-w / 2, -h / 2, d / 2);
  glVertex3f(w / 2, -h / 2, d / 2);
  glVertex3f(w / 2 , h / 2, d / 2);
  glVertex3f(-w / 2, h / 2, d / 2);
	
  //Back face
  
  
  glVertex3f(-w / 2, -h / 2, -d / 2);
  glVertex3f(-w / 2, h / 2, -d / 2);
  glVertex3f(w / 2, h / 2, -d / 2);
  glVertex3f(w / 2, -h / 2, -d / 2);
	
  glEnd();
  glPopMatrix();
}


