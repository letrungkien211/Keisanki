#include <vector>
using namespace std;
#ifndef SIERPINSKY3D_H
#define SIERPINSKY3D_H

#include "IFS.h"
#include "Vec3f.h"
#include "Affine.h"
#include "Common.h"
class Sierpinsky3D:public IFS{
public:
  Sierpinsky3D();
  void init(const float R=100.0f);
  void drawFractal(const vector<Vec3f> &points);
  void update(int timer_ms);
};

#endif
