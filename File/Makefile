#MAKEFILE

CC	= g++
RM	= rm -f

CFLAGS	= -g -Wall -O2 `pkg-config opencv --cflags`
LDFLAGS = -lglut -lGLU -lGL -lm -lc `pkg-config opencv --libs`

TARGET	= main 

OBJS	=  Common.o imageloader.o Affine.o Vec3f.o Object3D.o Cube.o Plane.o Ball.o  Collision.o Robot.o TextureMapping.o IFS.o Sierpinsky3D.o FractalTree.o main.o 

.cpp.o:
	${CC} -c ${CFLAGS} $<

TARGET: ${OBJS}
	${CC} -g -o $@ $^ ${LDFLAGS}

clean:
	${RM} ${TARGET} *.o *~ *#*
