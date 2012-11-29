#include <algorithm>
#include <vector>

using namespace std;


#ifndef CUBE_H
#define CUBE_H

#include "Plane.h"

class Cube:public Plane{
protected:
  float d;
public: 
  Cube();
  Cube(float w, float h, float d);
  ~Cube();
  void setSize(float w, float h, float d);
  void drawTexture();
  void drawNormal();
  void drawNoColor();
  
  virtual void draw();
  void print();
};

#endif
