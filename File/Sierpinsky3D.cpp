#include<algorithm>
#include<vector>
#include <cstdio>
#include<GL/glut.h>

using namespace std;
#include "Sierpinsky3D.h"
#include "Common.h"



Sierpinsky3D::Sierpinsky3D(){}

void Sierpinsky3D:: init(const float R){
  vector<Vec3f> points(5);
  points[0].set(0,0,R/2);
  points[1].set(-R/2,-R/2,-R/2);
  points[2].set(-R/2,R/2,-R/2);
  points[3].set(R/2,R/2, -R/2);
  points[4].set(R/2,-R/2, -R/2);

  setInitPoints(points);

  vector<Affine> mAffines(5);
  for(int i=0; i<5; ++i){
    mAffines[i].translate(points[i][0]/2.0,points[i][1]/2.0,points[i][2]/2.0);
    mAffines[i].scale(0.5f,0.5f,0.5f);
  }
  setTransformMatrixes(mAffines);
}

void Sierpinsky3D:: drawFractal(const vector<Vec3f> &points){
  static int color_change_cnt=0;
  if(color_change_cnt++>100){
    color_change_cnt=0;
    glColor3f(randf(1),randf(1),randf(1));
  }
  //glColor3f(1,0,0);
  glBegin(GL_LINES);
  for(int i=0; i<4; ++i){
    for(int j=i+1; j<5; ++j){
      if(i==0 || (j-i)!=2){
	glVertex3f(points[i][0], points[i][1], points[i][2]);
	glVertex3f(points[j][0], points[j][1], points[j][2]);
      }
    }
  }
  glEnd();
}


void Sierpinsky3D:: update(int timer_ms){
  static int  TIMER_MAX = 1000;
  static int timer =0;
  timer++;
  if(timer==TIMER_MAX/timer_ms){
    setColor(randf(0.5)+0.5, randf(0.5)+0.5,randf(0.5)+0.5);
    timer=0;
    times = (times+1)%5;
  }

  rotZ(randf(0.1)+0.1f);
  rotX(randf(0.1)+0.1f);
}
