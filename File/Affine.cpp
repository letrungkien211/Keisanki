#include<cmath>
#include<algorithm>
#include<cstdio>

#include<GL/glut.h>
#include "Affine.h"
#include "Vec3f.h"
#include "Common.h"

using namespace std;

/* Constructors*/
Affine::Affine(){
  identity();
}
Affine::Affine(const int bIdentity=true){
  if(bIdentity)
    identity();
  else{
    for(int i=0; i<16; ++i){
      m[i]=0;
    }
  }
}
Affine::Affine(float v[]){
  copy(v,v+16,m);
}
Affine::Affine(const Affine & other){
  *this = other;
}

/* Destructor*/
Affine::~Affine(){}


/* Matrix operators*/
// Matrix and Matrix
inline Affine Affine::operator*(const Affine &other) const{
  Affine result(0);
  int i,j, k;
  for(i=0; i<4; ++i){
    for(j=0; j<4; ++j){
      for(k=0; k<4; ++k){
	result.m[i+4*j]+= m[i+4*k]*(other.m[k+4*j]);
      }
    }
  }
  return result;
}

// Matrix and Vector
Vec3f Affine::operator*(const Vec3f &vec) const{
  return Vec3f(m[0]*(vec[0])+m[4]*(vec[1])+m[8]*(vec[2]) +m[12],
	       m[1]*(vec[0])+m[5]*(vec[1])+m[9]*(vec[2]) +m[13],
	       m[2]*(vec[0])+m[6]*(vec[1])+m[10]*(vec[2]) +m[14]);
}



// Apply this matrix transform in OpenGL
void Affine::applyGLTransform(){
  glMultMatrixf(this->m);
}

// Access data operators
float &Affine::operator[](int index){
  return m[index];
}

float Affine::operator[](int index) const{
  return m[index];
}

// Create new transformations matrixes  
Affine Affine:: getRotX(float angle){
  Affine result(1);
  result.m[1+4*1]=cos(RAD*angle);
  result.m[1+4*2]=-sin(RAD*angle);
  result.m[2+4*1]=sin(RAD*angle);
  result.m[2+4*2]=cos(RAD*angle);
  return result;
}
Affine Affine:: getRotY(float angle){
  
  Affine result(1);
  
  result.m[0]=cos(RAD*angle);
  result.m[0+4*2]=sin(RAD*angle);
  result.m[2+4*0]=-sin(RAD*angle);
  result.m[2+4*2]=cos(RAD*angle);
  return result;
}
Affine Affine:: getRotZ(float angle){
  Affine result(1);
  result.m[0]=cos(RAD*angle);
  result.m[0+4*1]=sin(RAD*angle);
  result.m[1+4*0]=-sin(RAD*angle);
  result.m[1+4*1]=cos(RAD*angle);
  return result;
}

Affine Affine:: getScale(float x, float y, float z){
  Affine result(1);
  result.m[0]=x;
  result.m[5]=y;
  result.m[10]=z;
  return result;
}

Affine Affine::getTranslate(float x, float y, float z){
  Affine result(1);
  result.m[12]=x; result.m[13]=y; result.m[14]=z;
  return result;
}


// Multiply this matrix with others to create new transforms
void Affine:: rotX(float angle){
  *this=(*this)*(this->getRotX(angle));
}
void Affine:: rotY(float angle){
  *this=(*this)*getRotY(angle);
}
void Affine:: rotZ(float angle){
  *this=(*this)*getRotZ(angle);
}
void Affine::translate(float x, float y, float z){
  *this=(*this)*getTranslate(x,y,z);
}
void Affine::scale(float x, float y, float z){
  *this =(*this)*getScale(x,y,z);
}

// Reset the matrix to identity's state
void Affine::identity(){
  int i,j;
  for(i=0; i<4; ++i){
    for(j =0; j<4; ++j){
      m[4*i+j] = (i==j) ? 1 : 0;
    }
  }
}
void Affine::identityRotate(){
  int i,j;
  for(i=0; i<3; ++i){
    for(j =0; j<3; ++j){
      m[4*i+j] = (i==j) ? 1 : 0;
    }
  }
}
void Affine::identityTranslate(){
  m[12]=m[13]=m[14]=0;
}
