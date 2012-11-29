#ifndef QOPENCVWIDGET_H
#define QOPENCVWIDGET_H

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QWidget>
class QOpenCVWidget:public QWidget{
public:
    QOpenCVWidget(QWidget *parent);
    ~QOpenCVWidget(void);
    void putImage(IplImage *cvimage);
};

#endif
