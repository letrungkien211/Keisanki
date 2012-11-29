#include <vector>
#ifndef IFS_H
#define IFS_H
#include "Object3D.h"
#include "Vec3f.h"
#include "Affine.h"

using namespace std;

class IFS: public Object3D{
protected:
  vector<Vec3f> initPoints;
  vector<Affine> mAffines;
  int times;
  
public:
  IFS();
  ~IFS();
  void setInitPoints(const vector<Vec3f> &points);
  void setTransformMatrixes(const vector<Affine> &m);  
  virtual void drawFractal(const vector<Vec3f> &p);
  void drawIFS(const vector<Vec3f> &p, int n);
  void draw();
  void draw(int n);
};
#endif
