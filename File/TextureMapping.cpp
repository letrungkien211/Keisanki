#include<GL/glut.h>
#include <cmath>
#include <cstdio>
#include "TextureMapping.h"

TextureMapping::TextureMapping(){}

void TextureMapping::setTexture(GLuint textureId, int texWidth, int texHeight, const float res){
  this->textureId = textureId;
  this->texWidth = texWidth;
  this->texHeight = texHeight;
  this->res = res;
}

void TextureMapping::toCylinder(const float THETA){
  float theta_step=2*THETA*res;
  float theta;
  
  float x;
  float ratio = (float)(texHeight)/(float)texWidth;
  float x_step = ratio*res;

  float texHeightHalf =0.3*(float)texHeight/2.0;  
  float    R= 0.3*texWidth/(2*THETA);  
  
  glPushMatrix();
  applyGLTransform();
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, textureId);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_QUADS);


  
  
  
  for(theta=-THETA, x=0; x<ratio; theta+=theta_step, x+=x_step){   
    glTexCoord2f(x,0);
    glVertex3f(R*sin(theta),+texHeightHalf,R*cos(theta));
    glTexCoord2f(x, 1);
    glVertex3f(R*sin(theta),-texHeightHalf,R*cos(theta));
    glTexCoord2f((x+x_step), 1);
    glVertex3f(R*sin(theta+theta_step),-texHeightHalf,R*cos(theta+theta_step));
    glTexCoord2f((x+x_step),0);
    glVertex3f(R*sin(theta+theta_step),+texHeightHalf,R*cos(theta+theta_step));
  }
  glEnd();
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}

void TextureMapping::toQuadricSurface(float Smin, float Smax, float Tmin, float Tmax,float R){
  float S, T;
  float s, t;

  float s_max=1;
  float t_max=(float)texHeight/(float)texWidth;

  float Ks= (float)s_max/(float)(Smax-Smin);
  float Kt= (float)t_max/(float)(Tmax-Tmin);

  float x,y,z;


  glPushMatrix();
  applyGLTransform();
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, textureId);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_QUADS);
	

  for(S=Smin; S<Smax; S+=res){
    for(T=Tmin; T<Tmax; T+=res){
      cal1(&s,&t,S,T,Smin, Tmin, Ks, Kt);
      cal2(R,S,T,&x,&y,&z);
      glTexCoord2f(s,t);
      glVertex3f(x,y,z);

      cal1(&s,&t,S+res,T,Smin, Tmin, Ks, Kt);
      cal2(R,S+res,T,&x,&y,&z);
      glTexCoord2f(s,t);
      glVertex3f(x,y,z);

      cal1(&s,&t,S+res,T+res,Smin, Tmin, Ks, Kt);
      cal2(R,S+res,T+res,&x,&y,&z);
      glTexCoord2f(s,t);
      glVertex3f(x,y,z);

      cal1(&s,&t,S,T+res,Smin, Tmin, Ks, Kt);
      cal2(R,S,T+res,&x,&y,&z);
      glTexCoord2f(s,t);
      glVertex3f(x,y,z);

    }
  }
  glEnd();
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}

void cal1(float *s, float *t, float S, float T, float Smin, float Tmin, float Ks, float Kt){
  *s=Ks*(S-Smin);
  *t=Kt*(T-Tmin);
}

void cal2(float R, float S, float T,float *x, float *y, float *z){
  *z= R*sin(S)*cos(T);
  *x= R*sin(S)*sin(T);
  *y= R*cos(S);
}



void TextureMapping::toSphere(const float R){
  toQuadricSurface(0,PI/2,0, PI,R);
}
