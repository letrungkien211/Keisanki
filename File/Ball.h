#ifndef Ball_h
#define Ball_h

#include "Object3D.h"
class Ball:public Object3D{
 protected:
  float radius;
 public:
  friend class Collision;
  Ball();
  
  // Access Data
  float getRadius();
  void setRadius(float r);
  virtual void draw();

  void move();
};
#endif
