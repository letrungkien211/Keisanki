#include <GL/glut.h>

#include<algorithm>
#include <vector>
#include "Object3D.h"
#include "Vec3f.h"
#include "Affine.h"

using namespace std;

Object3D::Object3D(){}

Object3D::~Object3D(){}

Vec3f Object3D::getColor(){return color;}
void Object3D:: setColor(float r, float g, float b){color.set(r,g,b);}
Vec3f Object3D::getPosition(){ return position;}
void Object3D:: setPosition(float x, float y, float z){position.set(x,y,z);}
Affine Object3D::getmAffine(){return mAffine;}
void Object3D:: setmAffine(Affine mAffine){this->mAffine = mAffine;}
Affine& Object3D::getmAffineBeforeDraw(){return mAffineBeforeDraw;}
void Object3D:: setmAffineBeforeDraw(Affine mAffineBeforeDraw){this->mAffineBeforeDraw = mAffineBeforeDraw;}
Affine& Object3D::getmAffineAfterDraw(){return mAffineAfterDraw;}
void Object3D:: setmAffineAfterDraw(Affine mAffineAfterDraw){this->mAffineAfterDraw = mAffineAfterDraw;}
Vec3f Object3D::getVelocity(){return velocity;}
void Object3D::setVelocity(float x, float y, float z){velocity.set(x,y,z);}
void Object3D::setAcceleration(float x, float y, float z){acceleration.set(x,y,z);}
Vec3f Object3D::getAcceleration(){return acceleration;}
Vec3f Object3D::getAngularVelocity(){return angularVelocity;}
void Object3D::setAngularVelocity(float rotX, float rotY, float rotZ){angularVelocity.set(rotX,rotY,rotZ);}
Vec3f Object3D::getAngle(){return angle;}
void Object3D::setAngle(float x, float y, float z){angle.set(x,y,z);}

// Tranformations
void Object3D:: translate(float offX, float offY, float offZ){
  mAffine.translate(offX, offY, offZ);
  position[0]+=offX; position[1]+=offY; position[2]+=offZ;
}
void Object3D:: rotZ(float angle){
  mAffine.rotZ(angle);
}
void Object3D:: rotY(float angle){
  mAffine.rotY(angle);
}
void Object3D:: rotX(float angle){
  mAffine.rotX(angle);
}
void Object3D:: scale(float scaleX, float scaleY, float scaleZ){
  mAffine.scale(scaleX, scaleY, scaleZ);
}
void Object3D::identity(){ mAffine.identity();}
void Object3D::identityRotate(){mAffine.identityRotate();}
void Object3D::identityTranslate(){mAffine.identityTranslate();position.set(0,0,0);}

void Object3D::applyGLTransform(){
  mAffine.applyGLTransform();
}

void Object3D::applyGLTransformBeforeDraw(){
  mAffineBeforeDraw.applyGLTransform();
}
void Object3D::applyGLTransformAfterDraw(){
  mAffineAfterDraw.applyGLTransform();
}

void Object3D::drawHierarchy(){
  glPushMatrix(); // +1
  applyGLTransform();

  glPushMatrix();
  applyGLTransformBeforeDraw();
  draw(); // first draw this
  applyGLTransformAfterDraw();
  glPopMatrix();

  for(int i=0; i<nodes.size(); ++i)
  glPushMatrix();
  for(int i=0; i<nodes.size(); ++i){
    nodes.at(i)->drawHierarchy(); // then draw its nodes
  }
  for(int i=0; i<nodes.size(); ++i)
    glPopMatrix();
  glPopMatrix(); // -1
}

// Hierarchy
Object3D* Object3D::childAt(int index){
  if(index<nodes.size())
    return nodes.at(index);
  return NULL;
}

int  Object3D::childErase(int index){
  if(index<nodes.size() && index>=0){
    nodes.erase(nodes.begin()+index);
    return true;
  }
  return (int)NULL;
}

int Object3D::childInsert(int index, Object3D *child){
  nodes.insert(nodes.begin()+index, child);
  return true;
}

void Object3D::draw(){

}
