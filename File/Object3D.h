#ifndef OBJECT3D_h
#define OBJECT3D_h

#include <vector>
#include <algorithm>
#include "Vec3f.h"
#include "Affine.h"

using namespace std;

class Object3D{
protected:
	Vec3f color;
	Affine mAffine;
	Affine mAffineBeforeDraw;
	Affine mAffineAfterDraw;
	Vec3f angle;
	Vec3f angularVelocity;
	Vec3f position;
	Vec3f velocity;
	Vec3f acceleration;

    bool isVisible;

    vector<Object3D*> nodes;

public:
	// Constructor
	Object3D();
	~Object3D();
	// Access data
	Vec3f getColor();
	void setColor(float r, float g, float b);
	Vec3f getPosition();
	void setPosition(float x, float y, float z);
	Affine getmAffine();
	void setmAffine(Affine mAffine);
	Affine& getmAffineBeforeDraw();
	void  setmAffineBeforeDraw(Affine mAffineBeforeDraw);
	Affine& getmAffineAfterDraw();
	void  setmAffineAfterDraw(Affine mAffineAfterDraw);
	void setCoordinateVisible(int visible);
	void setCoordinateAxises(float x, float y, float z);
	Vec3f getVelocity();
	void setVelocity(float x, float y, float z);
	Vec3f getAcceleration();
	void setAcceleration(float x, float y, float z);
	Vec3f getAngularVelocity();
	void setAngularVelocity(float rotX, float rotY,float rotZ);
	Vec3f getAngle();
	void setAngle(float angleX, float angleY, float angleZ);


	// Transformations
	void setRotateVelZ(float vel);
	void setRotateVelY(float vel);
	void setRotateVelX(float vel);

	void translate(float offX, float offY, float offZ);

	void rotZ(float angle);
	void rotY(float angle);
	void rotX(float angle);
	void scale(float scaleX, float scaleY, float scaleZ);

	void identity();
	void identityRotate();
	void identityTranslate();

	void applyGLTransform();
	void applyGLTransformBeforeDraw();
	void applyGLTransformAfterDraw();


    void drawHierarchy();
    virtual void draw();

    // Hiearchy
    Object3D* childAt(int index);
    int childInsert(int index,Object3D *child);
    int childErase(int index);

};
#endif
