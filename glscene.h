#ifndef GLSCENE_H
#define GLSCENE_H

#include <QGLWidget>
#include <QTimer>
#include <QPoint>
#include <QKeyEvent>
#include <opencv/cv.h>
#include <opencv/highgui.h>


using namespace Qt;
class GLScene : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLScene(QWidget *parent = 0);
    
    void initializeGL();
    virtual void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    
protected:

    MouseButton mouseButton;
    QPoint lastPos;
    QTimer timer;
    QTimer idle;

    int windowWidth, windowHeight;
    float fovy, near, far;
    float distance, pitch, yaw;
};

#endif // GLSCENE_H
