#ifndef PLANE_H
#define PLANE_H
#include "Object3D.h"

class Plane:public Object3D{
 protected:
  enum DRAW_TYPE{NORMAL,TEXTURE, NOCOLOR};
  float tex_width, tex_height;
  int textureId;
  float w,h;
  Vec3f normal;
  float distance;
  DRAW_TYPE drawType;
 public:

  friend class Collision;
  Plane();
  virtual void draw();
  void setSize(float w, float h);
  void setTexture(float width, float height, int id);
  void move();

  
  void setNormal(float x, float y, float z);
  float calculateDistance();
  void setDrawType(DRAW_TYPE type);
  virtual void drawNoColor();
  virtual void drawNormal();
  virtual void drawTexture();
};
#endif
