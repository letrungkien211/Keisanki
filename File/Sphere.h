#ifndef SPHERE_H
#define SPHERE_H

#include "Object3D.h"

class Sphere : public Object3D
{
public:
    Sphere();
    Sphere(const float R);
    void setRadius(float R){radius = R;}
protected:
    float radius;
    virtual void draw();
    void draw(float R);
};

#endif // SPHERE_H
