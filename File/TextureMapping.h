#include<GL/glut.h>

#ifndef TEXTUREMAPPING_H
#define TEXTUREMAPPING_H

#include "Common.h"
#include "Object3D.h"

class TextureMapping: public Object3D {
protected:
	GLuint textureId;
	int texWidth, texHeight;
	float res;
public:
	TextureMapping();
	
	void setTexture(GLuint textureId, int texWidth, int texHeight, const float resolution = 0.05);

	void toQuadricSurface(float Smin, float Smax, float Tmin, float Tmax, float Rx);
	void toCylinder(const float THETA=PI/2);

	void toSphere(const float R=100);

};

void cal1(float *s, float *t, float S, float T, float Smax, float Tmax, float Ks, float Kt);
void cal2(float R, float s, float t,float *x, float *y, float *z);
#endif
