#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <vector>
/* OpenGL */
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
/* OpenCV */
#include <opencv/cv.h>
#include <opencv/highgui.h>

/*******************************/
#include "imageloader.h"  // Use to load texture from bmp file
#include "Object3D.h"
#include "Plane.h"
#include "Cube.h"
#include "Robot.h"
#include "Ball.h"
#include "Collision.h"
#include "TextureMapping.h"
#include "IFS.h"
#include "Sierpinsky3D.h"
#include "Common.h"
#include "FractalTree.h"

float _guyPos=0;

const float FLOOR_TEXTURE_SIZE = 15.0f; //The size of each floor "tile"

/********************************/
#define SIZE_X 		640   // window width
#define SIZE_Y 		480   // window height 
#define DEG 		(2*PI/360.)   // Deg to radian

// Persperctive parameters
#define FOV_Y 		45    
#define NEAR_CLIP	0.0    
#define FAR_CLIP 	1000.0
#define DISTANCE_0	-100

// Control the scene
#define PLANES_NUM      6
#define BALLS_NUM       10
#define BOX_SIZE        400.0
#define BALL_MAXSIZE    3
#define BALL_MINSIZE    1


#define GRAVITY         9.8
const float TIME_BETWEEN_UPDATES = 0.01f;
const int TIMER_MS = 25; //The number of milliseconds to which the timer is set

int 		win_width =SIZE_X, win_height =SIZE_Y;
GLfloat 	distance_0 = DISTANCE_0, pitch = 0.0, yaw = 0.0;
GLint		mouse_button = -1;
GLint		mouse_x = 0, mouse_y =0;

GLuint		*textureId = new GLuint[6];
GLsizei 	*texWidth = new GLsizei[6];
GLsizei 	*texHeight = new GLsizei[6];

IplImage 	*frame;			/* OpenCV画像構造体 */
CvCapture* 	capture = 0;		/* Capture構造体 */
int 		dev_index = 0;		/* カメラのインデックス */
int 		cap_width =SIZE_X, cap_height =SIZE_Y;

/**********************************************************/
Collision collision;
vector<Plane*> box;
vector<Ball*> balls;

FractalTree fractalTree;
TextureMapping texmap;
Sierpinsky3D sierpinsky3D;
/**********************************************************/

Robot robot;
/**********************************
Control variables
***********************************/
// Opengl Callback functions
void keyboard(unsigned char c, int x, int y); // Keyboard handler
void keyboardGL(int key, int x, int y); // Special Keys handler
void display(void); // Display 
void reshape(int w, int h); // Called whenever window's size changes
void mouse(int button, int status, int x, int y);  // Mouse handler
void motion(int x, int y); // Mouse motion handler
void idle(void); // Idle callback

// Initialize functions
void my_initGL(void ); // Init every things
void my_init(void );
void my_initCV(int argc, char** argv );
void robot_init();
void balls_init();
void plane_init();
// Exit function
void my_exit(int e); // Exit

// Image and Texture functions
void define_texturesize(GLsizei *w0, GLsizei *h0, GLsizei *w1, GLsizei *h1);
GLuint loadTexture(GLuint textureId, IplImage* frame, int cap_width, int cap_height, int texWidth, int texHeight);
GLuint loadTexture(GLuint textureId,Image *image );

void robot_init(void ){
  robot.init(textureId);
}

void balls_init(){
  Ball *newBall = new Ball[BALLS_NUM] ;
  for(int i=0; i<BALLS_NUM; ++i){
    balls.insert(balls.begin()+i,newBall+i);
    balls.at(i)->setVelocity(randf(5),randf(5),randf(5));
    balls.at(i)->setRadius(5);
    balls.at(i)->setColor(randf(1.0),randf(1.0),randf(1.0));
    balls.at(i)->setAcceleration(0,-GRAVITY,0);
    balls.at(i)->translate(randf(BOX_SIZE/4), randf(BOX_SIZE/4), randf(BOX_SIZE/4));
  }
 
}

float n[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
float pos[6][3]={{BOX_SIZE/2,0,0},{-BOX_SIZE/2,0,0},{0,BOX_SIZE/2,0},{0,-BOX_SIZE/2,0},{0,0,BOX_SIZE/2},{0,0,-BOX_SIZE/2}};


void plane_init(){
  Plane *newPlane= new Plane[PLANES_NUM];
  for(int i=0; i<PLANES_NUM; ++i){
    box.insert(box.begin()+i, newPlane+i);
    box.at(i)->setNormal(n[i][0],n[i][1],n[i][2]);
    box.at(i)->translate(pos[i][0],pos[i][1],pos[i][2]);
    box.at(i)->calculateDistance();
    box.at(i)->setSize(BOX_SIZE,BOX_SIZE);
    box.at(i)->setTexture(0.5,1,textureId[0]);
  }
  box.at(0)->rotZ(-90);
  box.at(1)->rotZ(90);
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0,0,0,1);
  glLoadIdentity();
  
  glPushMatrix();
  glTranslatef(0,0,distance_0);
  //glRotatef( 45, 1.0, 0.0, 0.0);
  glRotatef(pitch,1,0,0);
  glRotatef(yaw,0,1,0);
  
  //glutWireCube(BOX_SIZE);
  
  //box[3]->draw();
  robot.drawHierarchy();
  //for(int i=0; i<BALLS_NUM; ++i)
  //balls.at(i)->draw();
  //box[2]->draw();
  
  glPushMatrix();  // +1
  glTranslatef(0,300,0);
  sierpinsky3D.draw();
  glPopMatrix();  // -1
  
  
  glPushMatrix();  // +1
  glTranslatef(0,-300,0);
  fractalTree.draw(4);
  glPopMatrix();   // -1
  
  glPushMatrix();   // +1
  glTranslatef(300,0,0);
  texmap.toSphere(300);
  glPopMatrix();   // -1

  glPushMatrix();   // +1
  glTranslatef(-300,0,0);
  texmap.toCylinder();
  glPopMatrix();   // -1
  

  glPopMatrix();  // -1
  glutSwapBuffers();
}

void keyboardGL(int key, int x, int y){
  switch(key){
  case GLUT_KEY_LEFT:
    robot.rotY(-10);
    break;
  case GLUT_KEY_RIGHT:
    robot.rotY(10);
    break;
  case GLUT_KEY_UP:
    robot.moveForward();
    break;
  case GLUT_KEY_DOWN:
    robot.moveBackward();
    break;

  }
    
}

void keyboard(unsigned char c, int x, int y){
  switch(c){
  case 32: /* Space */
    glutPostRedisplay();
    break;
  case 27: /* Escape */
    my_exit(1);
    break;
  case '8':
    robot.rotX(10);
    break;
  case '2':
    robot.rotX(-10);
    break;
  case '4':
    robot.rotZ(10);
    break;
  case '6':
    robot.rotZ(-10);
    break;
  case 'a':
    robot.childAt(3)->rotX(45/2);
    break;
  case 'b':
    robot.childAt(2)->rotX(-45/2);
    break;
  case 'c':
    robot.childAt(3)->rotX(-45/2);
    break;
  case 'd':
    robot.childAt(2)->rotX(-45/2);
    break;
  case 'e':
    robot.rotX(45);
    break;
  default:
    break;
  }
}

void mouse(int button, int state, int x, int y){  
  mouse_button = button;
  mouse_x = x; mouse_y = y;
  
  switch(button){
  case GLUT_LEFT_BUTTON:
    break;
  case GLUT_RIGHT_BUTTON:
    break;
  case 3:
  case 4:
    
    break;
  default:
    break;
  }
  glutPostRedisplay();
}

void motion(int x, int y)
{
  switch(mouse_button){
  case GLUT_LEFT_BUTTON:
    if( x==mouse_x && y==mouse_y ) return;
    yaw -= (GLfloat)( x - mouse_x ) /10.0;
    pitch -= (GLfloat)( y - mouse_y ) /10.0;
    break;
  case GLUT_RIGHT_BUTTON:
    if( y==mouse_y ) return;
    if( y < mouse_y ) distance_0 += (GLfloat)(mouse_y - y);
    else distance_0 -= (GLfloat)(y - mouse_y);
    if( -distance_0 < NEAR_CLIP ) distance_0 = -NEAR_CLIP;
    if( -distance_0 > FAR_CLIP ) distance_0 = -FAR_CLIP;
    break;
  }
  mouse_x = x;
  mouse_y = y;
  glutPostRedisplay();
}

void idle(void)
{
  // Texture
  if (capture) { 
    frame = cvQueryFrame(capture);
   
    cvCvtColor(frame, frame, CV_BGR2RGB);

    if (frame->origin==0) {
      cvFlip(frame, frame, 0);
    }
  }
  
  if (frame->origin==0){
    cvFlip(frame, frame, 0);
  }
glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
  glBindTexture( GL_TEXTURE_2D, textureId[0] );
  glTexSubImage2D( GL_TEXTURE_2D, 0, 0, 0, frame->width, frame->height,
		   GL_RGB, GL_UNSIGNED_BYTE, frame->imageData ); /* 画像の更新 */

  glutPostRedisplay();
}

void reshape(int w, int h)
{
  win_width =  w; win_height =  h;
  glViewport(0, 0, win_width, win_height);
    
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(FOV_Y, (GLfloat)w/(GLfloat)h, NEAR_CLIP, FAR_CLIP);
    
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  
  glTranslatef(0,0,distance_0);
  glutPostRedisplay();
}

void my_initCV(int argc, char **argv)
{
  IplImage * canny;
  capture = cvCreateCameraCapture(dev_index);
  if (capture) { 

    frame = cvQueryFrame(capture);
    
    cap_width = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
    cap_height = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);

    if (frame->origin==0) {
    cvFlip(frame, frame, 0);
    }
    
    
  } else { 
    fprintf(stderr, "Found No Camera\n");
    exit(-1);
  }
  
  if (frame->origin==0) {
    cvFlip(frame, frame, 0);
  }
  
  IplImage *canny1, *canny2;
  canny = cvCreateImage(cvGetSize(frame), IPL_DEPTH_32F,3);
  canny1 = cvCreateImage(cvGetSize(frame), IPL_DEPTH_32F,3);

 
  win_width = cap_width;
  win_height = cap_height;
}

void my_init(void ){
  my_initGL();
  robot_init();
  balls_init();
  plane_init();
  
  texmap.setTexture(textureId[0], texWidth[0], texHeight[0]);
}

void my_initGL()
{
  // Enable and disable 
  //glEnable(GL_DEPTH_TEST);
  //glEnable(GL_COLOR_MATERIAL);
  //glEnable(GL_LIGHTING);
  //glEnable(GL_LIGHT0);
  //glEnable(GL_LIGHT1);
  //glEnable(GL_NORMALIZE);
   
  glEnable(GL_BLEND);


  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  
  //glDisable(GL_CULL_FACE);
  glGenTextures( 3, textureId );
  
  define_texturesize( &cap_width, &cap_height, &texWidth[0], &texHeight[0] ); 
  loadTexture(textureId[0],frame, cap_width,cap_height, texWidth[0], texHeight[0]);
  Image* image = loadBMP("vtr.bmp");
  loadTexture(textureId[1],image);
  delete image;

  IplImage* tmp = cvLoadImage("lena512.bmp", CV_LOAD_IMAGE_UNCHANGED);
  define_texturesize( &tmp->width, &tmp->height, &texWidth[1], &texHeight[1] ); 
  loadTexture(textureId[2],tmp, tmp->width, tmp->height, texWidth[2], texHeight[2]);

  glClear( GL_COLOR_BUFFER_BIT );
}

void my_exit(int e){
  if (capture) cvReleaseCapture(&capture);
  exit(e);
}

void update(int value) {
  //collision.handleBallsPlanesCollisions(balls,box);
  //for(int i=0; i<BALLS_NUM; ++i) balls.at(i)->move();
  //texmap.rotY(5);
  sierpinsky3D.update(TIMER_MS);
  glutPostRedisplay();
  glutTimerFunc(TIMER_MS, update, 0);


  _guyPos += 0.08f;
  while (_guyPos > FLOOR_TEXTURE_SIZE) {
    _guyPos -= FLOOR_TEXTURE_SIZE;
  }
  
}

int main(int argc, char **argv){
  srand((unsigned int)time(0));
  char	title[128];

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  
  my_initCV(argc, argv); // Init camera
  
  glutInitWindowSize(win_width, win_height);
  sprintf(title, "OpenCV Video Texture - (%dx%d)", cap_width, cap_height);
  glutCreateWindow(title);
  
  my_init();  // Init rendering and data

  
  sierpinsky3D.init();
  fractalTree.init();

  // OpenGL callback functions
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);

  // Special callback functions
  glutSpecialFunc(keyboardGL);

  // Timer function
  glutTimerFunc(TIMER_MS, update, 0);
  glutMainLoop();
  return 0;
}
