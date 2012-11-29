#include <vector>
using namespace std;

#ifndef FRACTALTREE_H
#define FRACTALTREE_H

#include "IFS.h"
#include "Vec3f.h"
#include "Affine.h"
#include "Common.h"

class FractalTree:public IFS{
public:
  FractalTree();
  void init(const float len = 30);
  void drawFractal(const vector<Vec3f> &points);
};

#endif
