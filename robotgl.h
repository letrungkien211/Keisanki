#ifndef ROBOTGL_H
#define ROBOTGL_H

#include "glscene.h"
#include "./File/Robot.h"
#include <QKeyEvent>

class RobotGL : public GLScene
{
    Q_OBJECT
public:
    explicit RobotGL(QWidget *parent = 0);
    void initializeGL();
    virtual void paintGL();
    void resizeGL(int w, int h);
    void updateGL();

    void keyPressEvent(QKeyEvent *event);

private:
    Robot *robot;

public slots:
    void moveForward(const float dis = 5);
    void moveBackward(const float dis = 5);
    void turnLeft(const float angle = 5);
    void turnRight(const float angle = 5);
    void climb(const float height = 20);
    void descend(const float height = 20);
    void identity();
    void wave();
};
#endif // ROBOTGL_H
