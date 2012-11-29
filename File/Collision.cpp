#include "Collision.h"

int Collision::testBallBallCollision(const Ball & b1, const Ball & b2){
  float d= b1.radius+b2.radius;

  if((b1.position-b2.position).magnitudeSquared()<d*d){
    Vec3f netVelocity = b1.velocity-b2.velocity;
    Vec3f displacement = b1.position-b2.position;
    return netVelocity*displacement<0;
  }
  else
    return false;
}

int Collision::testBallPlaneCollision(const Ball & ball, const Plane & plane){
  Vec3f normal = plane.normal;
  return ball.position*normal+ball.radius>plane.distance &&
    ball.velocity*(normal)>0;
}

void Collision:: handleBallPlaneCollision(Ball &ball, Plane & plane){
  if(testBallPlaneCollision(ball, plane)){
    Vec3f normal=plane.normal;
    ball.velocity-=2*normal*(ball.velocity*normal);
  }
}


void Collision:: handleBallBallCollision(Ball &b1, Ball &b2){
  if(testBallBallCollision(b1,b2)){
    Vec3f displacement =(b1.position -b2.position).normalize();
    b1.velocity-=2*displacement*(b1.velocity*displacement);
    b2.velocity-=2*displacement*(b2.velocity*displacement);
  }
}
void Collision:: handleBallBallCollisions(vector<Ball*> &balls){
  for(int i=0; i<balls.size()-1; ++i){
    for(int j=0; j<balls.size(); ++j){
      handleBallBallCollision(*balls.at(i), *balls.at(j));
    }
  }
}

void Collision::handleBallPlanesCollisions(Ball &ball, vector<Plane*> &planes){
  for(int i=0; i<planes.size();++i){
    handleBallPlaneCollision(ball, *planes.at(i));
  }
}

void Collision::handleBallsPlanesCollisions(vector<Ball*> &balls, vector<Plane*> &plane){
  for (int i=0; i<balls.size(); ++i){
    handleBallPlanesCollisions(*balls.at(i), plane);
  }
}



