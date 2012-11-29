#ifndef AFFINE_H
#define AFFINE_H

#include "Vec3f.h"
class Affine{
 private:
  float m[16];

 public:
  // Constructor
  Affine(const int bIdentity);
  Affine(float v[]);
  Affine(const Affine & other);
  Affine();
  ~Affine();
  
  // Multiply Operator
  Affine operator*(const Affine &other) const;
  Vec3f operator*(const Vec3f & vec) const;
  
  void applyGLTransform();

  // Apply transform
  float &operator[](int index);
  float operator[](int index) const;
  
  // Rotation Matrix
  void rot(float angle, float x, float y, float z);
  void rotX(float angle);
  void rotY(float angle);
  void rotZ(float angle);
  void scale(float x, float y, float z);
  // Translatation Matrix
  void translate(float x, float y, float z);

  // Rotation Matrix
  Affine getRotX(float angle);
  Affine getRotY(float angle);
  Affine getRotZ(float angle);
  Affine getScale(float x, float y, float z);
  // Translatation Matrix
  Affine getTranslate(float x, float y, float z);
  
  // Identity
  void identityRotate();
  void identityTranslate();
  void identity();
};

#endif
