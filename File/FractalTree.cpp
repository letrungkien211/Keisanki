#include <vector>
#include <GL/glut.h>
#include <cmath>
using namespace std;
#include "FractalTree.h"
#include "Vec3f.h"
#include "Affine.h"
#include "Common.h"

FractalTree::FractalTree(){}
void FractalTree:: init(const float len){
  vector<Vec3f> points(5);
  
  float x,y;
  for(int i=0; i<5; ++i){
    x=i*len*cos((90-i*3)*RAD);
    y=i*len*sin((90-i*3)*RAD);
    points[i].set(x,y,0);
  }
    
  setInitPoints(points);
  
  vector<Affine> mAffines(6);

  for(int i=5; i<9; ++i){
    mAffines[i-5].translate(points[i/2][0], points[i/2][1], points[i/2][2]);
    mAffines[i-5].scale(0.75,0.75,0.75);
    if(i%2){	
      mAffines[i-5].rotZ(60);
      mAffines[i-5].rotY(30);
    }
    else{
      mAffines[i-5].rotZ(-60);
      mAffines[i-5].rotY(30);
    }
  }
  
  mAffines[5].translate(points[4][0], points[4][1], points[4][2]);
  mAffines[5].scale(0.3f,0.3f,0.3f);
  mAffines[5].rotZ(60);
  
  setTransformMatrixes(mAffines);
  
}
void FractalTree:: drawFractal(const vector<Vec3f> &points){
  glBegin(GL_LINE_STRIP);
  static int color_change_cnt=0;
  if(color_change_cnt++>10){
    color_change_cnt=0;
    glColor3f(randf(1),randf(1),randf(1));
  }
  for(int i=0; i<5; ++i){
    glVertex3f(points[i][0], points[i][1], points[i][2]);
  }
  glEnd();
}
