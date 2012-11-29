#ifndef CYLINDER_H
#define CYLINDER_H
#include "Object3D.h"

class Cylinder : public Object3D
{
public:
    Cylinder();
    Cylinder(float r, float h);
    virtual void draw();
    void draw(float r, float h);
    void setRadius(float r){ radius = r;}
    void setHeight(float h){height =h;}
protected:
    float radius, height;

};

#endif // CYLINDER_H
