#-------------------------------------------------
#
# Project created by QtCreator 2012-05-28T22:31:40
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = Kadai
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    File/Vec3f.cpp \
    File/Sierpinsky3D.cpp \
    File/Robot.cpp \
    File/Object3D.cpp \
    File/imageloader.cpp \
    File/IFS.cpp \
    File/Cube.cpp \
    File/Common.cpp \
    File/Collision.cpp \
    File/Affine.cpp \
    sierpinsky3dgl.cpp \
    glscene.cpp \
    robotgl.cpp \
    File/Sphere.cpp \
    File/Cylinder.cpp \
    File/Plane.cpp
HEADERS  += mainwindow.h \
    File/Vec3f.h \
    File/Sierpinsky3D.h \
    File/Robot.h \
    File/Object3D.h \
    File/IFS.h \
    File/Cube.h \
    File/Common.h \
    File/Affine.h \
    sierpinsky3dgl.h \
    glscene.h \
    robotgl.h \
    File/Sphere.h \
    File/Cylinder.h \
    File/Plane.h

FORMS    += mainwindow.ui

LIBS    += -lglut -lGLU -lGL `pkg-config opencv --cflags --libs`
