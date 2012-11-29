#include <vector>
#include <GL/glut.h>
#include "IFS.h"
using namespace std;

IFS:: IFS(){}
IFS:: ~IFS(){}

void IFS:: setInitPoints(const vector<Vec3f> &points){
  initPoints.resize(points.size());
  for(int i=0; i<points.size(); ++i)
    initPoints.insert(initPoints.begin()+i, points[i]);
}
  
void IFS:: setTransformMatrixes(const vector<Affine> &m){
  mAffines.resize(m.size());
  for(int i=0; i<m.size(); ++i)
    mAffines[i]=m[i];
}
  
void IFS:: drawFractal(const vector<Vec3f> &){}

void IFS:: drawIFS(const vector<Vec3f> &p, int n){
  vector<Vec3f> tmp;
  tmp.resize(p.size());

  glPushMatrix();
  applyGLTransform();
  if(n<=0)
    drawFractal(p);
  else{
    for(int i=0; i<mAffines.size(); ++i){
      for(int j=0; j<p.size();++j){
	tmp[j]=mAffines[i]*p[j];
      }
      drawIFS(tmp, n-1);
    }
  }
  glPopMatrix();
}

void IFS:: draw(){
  drawIFS(initPoints,times);
}
void IFS:: draw(int n){
  drawIFS(initPoints,n);
}
