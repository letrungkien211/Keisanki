#ifndef SIERPINSKY3DGL_H
#define SIERPINSKY3DGL_H

#include "glscene.h"
#include "./File/Sierpinsky3D.h"

class Sierpinsky3DGL : public GLScene
{
    Q_OBJECT
public:
    explicit Sierpinsky3DGL(QWidget *parent = 0);
    
    void initializeGL();
    virtual void paintGL();
    void resizeGL(int w, int h);
    void updateGL();
private:
    Sierpinsky3D *sier;
};

#endif // SIERPINSKY3DGL_H
