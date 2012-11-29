#ifndef ROBOT_H
#define ROBOT_H
#include<algorithm>
#include <GL/glut.h>
#include <cmath>
#include "Cube.h"
#include "Common.h"
#include "Cylinder.h"
#include "Sphere.h"
class Robot:public Cube{
  struct OneMove{
    int state;
    float angle;
    void calAngle(float tan){
        angle = 180*atan(tan)/PI;
    }
  };
 protected:
  float robotSize;
  OneMove oneMove;
 public:
  Robot();
  ~Robot();
  Cube lleg,lleg1, rleg,rleg1, rhand,rhand1, lhand,lhand1;
  Cylinder neck;
  Sphere head;
  void init(const GLuint *textureId=NULL);
  void setRobotSize(float robotSize){this->robotSize=robotSize;}
  void setOneMove(int state, float angle){this->oneMove.state=state; this->oneMove.angle=angle;}

  void moveForward(const float dis = 5);
  void moveBackward(const float dis = 5);

  void climb(const float height);
  void descend(const float height);
  void wave();
  void reset();
};

#endif
