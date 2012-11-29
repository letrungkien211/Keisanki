#include<cmath>
#include "Robot.h"

#define PI 3.1415926535897932

Robot::Robot(){
    robotSize=40;
    oneMove.state=0;
    oneMove.angle=10;
}
Robot::~Robot(){}

void Robot::init(const GLuint *textureId){
    GLuint tex[6];
    if(!textureId){
        tex[0]=tex[1]=0;
    }
    else{
        for(int i=0; i<6; ++i){
            tex[i] = textureId[i];
        }
    }

    // Body
    setSize(robotSize/2, robotSize, robotSize/8);
    translate(0, 3*robotSize/2.0,0);
    setColor(1,0,0);
    //setDrawType();
    //setTexture(0.5,1,tex[0]);

    // Left Leg
    lleg.setSize(robotSize/8, robotSize/2, robotSize/10);
    lleg.translate(-robotSize/8, -robotSize/2, 0);
    lleg.getmAffineBeforeDraw().translate(0,-robotSize/4,0);
    lleg.setColor(0,1,0);
    // Left Leg 1
    lleg1.setSize(robotSize/8, robotSize/2, robotSize/10);
    lleg1.translate(0, -robotSize/2, 0);
    lleg1.getmAffineBeforeDraw().translate(0,-robotSize/4,0);

    // Right Leg
    rleg.setSize(robotSize/8, robotSize/2, robotSize/10);
    rleg.translate(robotSize/8, -robotSize/2, 0);
    rleg.getmAffineBeforeDraw().translate(0,-robotSize/4,0);
    rleg.setColor(0,0,1);

    // Right Leg 1
    rleg1.setSize(robotSize/8, robotSize/2, robotSize/10);
    rleg1.translate(0, -robotSize/2, 0);
    rleg1.getmAffineBeforeDraw().translate(0,-robotSize/4,0);

    // Left Hand
    lhand.setSize(robotSize/10, robotSize/2, robotSize/10);
    lhand.translate(-3*robotSize/10,robotSize/2,0);
    lhand.getmAffineBeforeDraw().translate(0,-robotSize/4,0);

    lhand.setColor(0.5,0.5,0.5);
    // Left Hand 1
    lhand1.setSize(robotSize/10, robotSize/2, robotSize/10);
    lhand1.translate(0,-robotSize/2,0);
    lhand1.getmAffineBeforeDraw().translate(0,-robotSize/4,0);

    // Right Hand
    rhand.setSize(robotSize/10, robotSize/2, robotSize/10);
    rhand.translate(3*robotSize/10,robotSize/2,0);
    rhand.getmAffineBeforeDraw().translate(0,-robotSize/4,0);

    rhand.setColor(0.5,1.0,0.5);
    // Right Hand 1
    rhand1.setSize(robotSize/10, robotSize/2, robotSize/10);
    rhand1.translate(0,-robotSize/2,0);
    rhand1.getmAffineBeforeDraw().translate(0,-robotSize/4,0);

    // Head

    neck.setRadius(robotSize/10);
    neck.setHeight(robotSize/8);
    neck.translate(0, 5*robotSize/8, 0);

    head.setRadius(robotSize/5);
    head.setColor(0.4,0.3,0.3);
    head.translate(0, 2*robotSize/8, 0);
    head.getmAffineBeforeDraw().translate(0,-robotSize/4,0);
    //head.setDrawType(TEXTURE);
    //head.setTexture(1,1,tex[1]);

    // Create robot structure

    lleg.childInsert(0,&lleg1);
    rleg.childInsert(0,&rleg1);

    lhand.childInsert(0,&lhand1);
    rhand.childInsert(0,&rhand1);

    neck.childInsert(0, &head);

    childInsert(0,&rhand);
    childInsert(1,&lhand);
    childInsert(2,&rleg);
    childInsert(3,&lleg);
    childInsert(4,&neck);
}

void Robot::moveForward(const float dis){
    oneMove.calAngle(dis/robotSize);
    if(oneMove.state){
        oneMove.state=0;
        lleg.rotX(oneMove.angle);
        rleg.rotX(-oneMove.angle);
        lhand.rotX(oneMove.angle);
        rhand.rotX(-oneMove.angle);

        translate(0,0,dis);
    }
    else{
        oneMove.state=1;
        lleg.rotX(-oneMove.angle);
        rleg.rotX(oneMove.angle);
        lhand.rotX(-oneMove.angle);
        rhand.rotX(oneMove.angle);

        translate(0,0,dis);

    }
}
void Robot::moveBackward(const float dis){
    oneMove.calAngle(dis/robotSize);
    if(oneMove.state){
        oneMove.state=0;
        lleg.rotX(oneMove.angle);
        rleg.rotX(-oneMove.angle);
        lhand.rotX(oneMove.angle);
        rhand.rotX(-oneMove.angle);

        translate(0,0,-dis);
    }
    else{
        oneMove.state=1;
        lleg.rotX(-oneMove.angle);
        rleg.rotX(oneMove.angle);
        lhand.rotX(-oneMove.angle);
        rhand.rotX(oneMove.angle);

        translate(0,0,-dis);
    }
}


void Robot::climb(const float height){
    static int state = 0;
    if(!state){
        rleg.rotX(-90);
        rleg1.rotX(90);
        lhand.rotX(30);
        lhand1.rotX(15);
        rhand.rotX(-30);
        rhand1.rotX(-15);
    }
    else{
        rleg.rotX(90);
        rleg1.rotX(-90);
        lhand.rotX(-30);
        lhand1.rotX(-15);
        rhand.rotX(30);
        rhand1.rotX(15);
        translate(0, height,height);
    }
    state = (state+1)%2;
}

void Robot::descend(const float height){
    static int state = 0;
    if(!state){
        translate(0, -height, -height);
        //rleg.rotX(30);
        rleg1.rotX(-90);
        lhand.rotX(30);
        lhand1.rotX(15);
        rhand.rotX(-30);
        rhand1.rotX(-15);

    }
    else{
        //rleg.rotX(-30);
        lhand.rotX(-30);
        lhand1.rotX(-15);
        rhand.rotX(30);
        rhand1.rotX(15);

        rleg1.rotX(90);
    }
    state = (state +1) %2;
}

void Robot::reset(){
    rhand.identityRotate();
    rhand1.identityRotate();
    lhand.identityRotate();
    lhand1.identityRotate();
    rleg.identityRotate();
    rleg1.identityRotate();
    lleg.identityRotate();
    lleg1.identityRotate();
}

void Robot::wave(){
    static int state = 0;
    if(!state){
        rhand.rotX(180);
        state=1;
    }
    else if(state ==1){
        rhand1.rotZ(45);
        state=2;
    }
    else if(state==2){
        rhand1.rotZ(-45);
        state = 1;
    }
}
