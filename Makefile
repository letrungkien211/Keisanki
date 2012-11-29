#############################################################################
# Makefile for building: Kadai
# Generated by qmake (2.01a) (Qt 4.8.1) on: Fri Nov 30 01:09:51 2012
# Project:  Kadai.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile Kadai.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4 -I/usr/X11R6/include -I. -I. `pkg-config opencv --cflags`
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -L/usr/X11R6/lib64 -lglut -lGLU `pkg-config opencv --libs` -lQtOpenGL -lQtGui -lQtCore -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
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
		File/Plane.cpp moc_mainwindow.cpp \
		moc_sierpinsky3dgl.cpp \
		moc_glscene.cpp \
		moc_robotgl.cpp
OBJECTS       = main.o \
		mainwindow.o \
		Vec3f.o \
		Sierpinsky3D.o \
		Robot.o \
		Object3D.o \
		imageloader.o \
		IFS.o \
		Cube.o \
		Common.o \
		Collision.o \
		Affine.o \
		sierpinsky3dgl.o \
		glscene.o \
		robotgl.o \
		Sphere.o \
		Cylinder.o \
		Plane.o \
		moc_mainwindow.o \
		moc_sierpinsky3dgl.o \
		moc_glscene.o \
		moc_robotgl.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Kadai.pro
QMAKE_TARGET  = Kadai
DESTDIR       = 
TARGET        = Kadai

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Kadai.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtOpenGL.prl \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile Kadai.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/opengl.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtOpenGL.prl:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile Kadai.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Kadai1.0.0 || $(MKDIR) .tmp/Kadai1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Kadai1.0.0/ && $(COPY_FILE) --parents mainwindow.h File/Vec3f.h File/Sierpinsky3D.h File/Robot.h File/Object3D.h File/IFS.h File/Cube.h File/Common.h File/Affine.h sierpinsky3dgl.h glscene.h robotgl.h File/Sphere.h File/Cylinder.h File/Plane.h .tmp/Kadai1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp File/Vec3f.cpp File/Sierpinsky3D.cpp File/Robot.cpp File/Object3D.cpp File/imageloader.cpp File/IFS.cpp File/Cube.cpp File/Common.cpp File/Collision.cpp File/Affine.cpp sierpinsky3dgl.cpp glscene.cpp robotgl.cpp File/Sphere.cpp File/Cylinder.cpp File/Plane.cpp .tmp/Kadai1.0.0/ && $(COPY_FILE) --parents mainwindow.ui .tmp/Kadai1.0.0/ && (cd `dirname .tmp/Kadai1.0.0` && $(TAR) Kadai1.0.0.tar Kadai1.0.0 && $(COMPRESS) Kadai1.0.0.tar) && $(MOVE) `dirname .tmp/Kadai1.0.0`/Kadai1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Kadai1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_sierpinsky3dgl.cpp moc_glscene.cpp moc_robotgl.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_sierpinsky3dgl.cpp moc_glscene.cpp moc_robotgl.cpp
moc_mainwindow.cpp: mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_sierpinsky3dgl.cpp: glscene.h \
		File/Sierpinsky3D.h \
		File/IFS.h \
		File/Object3D.h \
		File/Vec3f.h \
		File/Affine.h \
		File/Common.h \
		sierpinsky3dgl.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) sierpinsky3dgl.h -o moc_sierpinsky3dgl.cpp

moc_glscene.cpp: glscene.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) glscene.h -o moc_glscene.cpp

moc_robotgl.cpp: glscene.h \
		File/Robot.h \
		File/Cube.h \
		File/Plane.h \
		File/Object3D.h \
		File/Vec3f.h \
		File/Affine.h \
		File/Common.h \
		File/Cylinder.h \
		File/Sphere.h \
		robotgl.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) robotgl.h -o moc_robotgl.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui \
		sierpinsky3dgl.h \
		robotgl.h \
		glscene.h \
		File/Sierpinsky3D.h \
		File/IFS.h \
		File/Object3D.h \
		File/Vec3f.h \
		File/Affine.h \
		File/Common.h \
		glscene.h \
		File/Robot.h \
		File/Cube.h \
		File/Plane.h \
		File/Object3D.h \
		File/Vec3f.h \
		File/Affine.h \
		File/Common.h \
		File/Cylinder.h \
		File/Sphere.h
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

Vec3f.o: File/Vec3f.cpp File/Vec3f.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Vec3f.o File/Vec3f.cpp

Sierpinsky3D.o: File/Sierpinsky3D.cpp File/Sierpinsky3D.h \
		File/IFS.h \
		File/Object3D.h \
		File/Vec3f.h \
		File/Affine.h \
		File/Common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Sierpinsky3D.o File/Sierpinsky3D.cpp

Robot.o: File/Robot.cpp File/Robot.h \
		File/Cube.h \
		File/Plane.h \
		File/Object3D.h \
		File/Vec3f.h \
		File/Affine.h \
		File/Common.h \
		File/Cylinder.h \
		File/Sphere.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Robot.o File/Robot.cpp

Object3D.o: File/Object3D.cpp File/Object3D.h \
		File/Vec3f.h \
		File/Affine.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Object3D.o File/Object3D.cpp

imageloader.o: File/imageloader.cpp File/imageloader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o imageloader.o File/imageloader.cpp

IFS.o: File/IFS.cpp File/IFS.h \
		File/Object3D.h \
		File/Vec3f.h \
		File/Affine.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o IFS.o File/IFS.cpp

Cube.o: File/Cube.cpp File/Cube.h \
		File/Plane.h \
		File/Object3D.h \
		File/Vec3f.h \
		File/Affine.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Cube.o File/Cube.cpp

Common.o: File/Common.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Common.o File/Common.cpp

Collision.o: File/Collision.cpp File/Collision.h \
		File/Ball.h \
		File/Object3D.h \
		File/Vec3f.h \
		File/Affine.h \
		File/Plane.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Collision.o File/Collision.cpp

Affine.o: File/Affine.cpp File/Affine.h \
		File/Vec3f.h \
		File/Common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Affine.o File/Affine.cpp

sierpinsky3dgl.o: sierpinsky3dgl.cpp sierpinsky3dgl.h \
		glscene.h \
		File/Sierpinsky3D.h \
		File/IFS.h \
		File/Object3D.h \
		File/Vec3f.h \
		File/Affine.h \
		File/Common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sierpinsky3dgl.o sierpinsky3dgl.cpp

glscene.o: glscene.cpp glscene.h \
		File/imageloader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o glscene.o glscene.cpp

robotgl.o: robotgl.cpp robotgl.h \
		glscene.h \
		File/Robot.h \
		File/Cube.h \
		File/Plane.h \
		File/Object3D.h \
		File/Vec3f.h \
		File/Affine.h \
		File/Common.h \
		File/Cylinder.h \
		File/Sphere.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o robotgl.o robotgl.cpp

Sphere.o: File/Sphere.cpp File/Sphere.h \
		File/Object3D.h \
		File/Vec3f.h \
		File/Affine.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Sphere.o File/Sphere.cpp

Cylinder.o: File/Cylinder.cpp File/Cylinder.h \
		File/Object3D.h \
		File/Vec3f.h \
		File/Affine.h \
		File/Common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Cylinder.o File/Cylinder.cpp

Plane.o: File/Plane.cpp File/Plane.h \
		File/Object3D.h \
		File/Vec3f.h \
		File/Affine.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Plane.o File/Plane.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_sierpinsky3dgl.o: moc_sierpinsky3dgl.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_sierpinsky3dgl.o moc_sierpinsky3dgl.cpp

moc_glscene.o: moc_glscene.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_glscene.o moc_glscene.cpp

moc_robotgl.o: moc_robotgl.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_robotgl.o moc_robotgl.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
