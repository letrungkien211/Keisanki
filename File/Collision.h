#include<vector>

#ifndef Collision_h
#define Collision_h

#include "Ball.h"
#include "Plane.h"
using namespace std;

class Collision{
 public:
  int testBallBallCollision(const Ball & b1, const Ball & b2);
  int testBallPlaneCollision(const Ball & ball, const Plane & plane);
  void handleBallBallCollision(Ball &b1, Ball &b2);
  void handleBallBallCollisions(vector<Ball*> &balls);
  void handleBallPlaneCollision(Ball &ball, Plane & plane);
  void handleBallPlanesCollisions(Ball &ball, vector<Plane*> &planes);
  void handleBallsPlanesCollisions(vector<Ball*> &balls, vector<Plane*> &plane); 
}; 
    
#endif
