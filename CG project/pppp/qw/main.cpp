#include<cstdio>
#include <windows.h>
#include<math.h>
#include <vector>
#include <cstdlib>
# define PI 3.14159265358979323846
#include <GL/gl.h>
#include <GL/glut.h>
#include<MMSystem.h>
#include <iostream>

GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat speed = 0.1f;

void update2(int value) {

  if(position > 1.0)
position = -1.0f;

 position += speed;

 glutPostRedisplay();



if(position2 > 1.0)
position2 = -1.0f;

 position2 += speed;

glutPostRedisplay();

glutTimerFunc(100, update2, 0);
}


void update(int value) {

 if(position2 <-1.0)
position2 = 1.0f;

 position2 -= speed;

 glutPostRedisplay();

glutTimerFunc(100, update, 0);
}
void DrawCircle(float cx, float cy, float r, int num_segments) {

 glBegin(GL_TRIANGLE_FAN);
for (int i = 0; i < num_segments; i++)
{
float theta = (2.0f * 3.1416f * float(i) )/ float(num_segments);//get current angle

 float x = r * cosf(theta);//calculate x
float y = r * sinf(theta);//calculate y

 glVertex2f(x + cx, y + cy);//output vertex

 }
glEnd();

}

void display() {
glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);


glPushMatrix();
glTranslatef(position,position2, 1.0f);
DrawCircle(0.0f,0.0f,0.3f,120);

glPopMatrix();


 glFlush();
}

void handleMouse(int button, int state, int x, int y) {
if (button == GLUT_LEFT_BUTTON)
{
if(position>=1.0f)
{

 position-=0.2f;
}
else
{
speed=0.0f;
}

 speed -= 0.1f;
position+=speed;

 }

if (button == GLUT_RIGHT_BUTTON)
{

 if(position<=-1.0f)
{

 position=1.0f;
}
else
{
speed=0.0f;
}

 speed -= 0.1f;
position-=speed;
}
glutPostRedisplay();

}


void SpecialInput(int key, int x, int y)
{
switch(key)
{
case GLUT_KEY_UP:
//do something here
glutTimerFunc(100, update2, 0);
break;
case GLUT_KEY_DOWN:
//do something here
// position2 -= speed;
//position -= speed;
glutTimerFunc(100, update, 0);
break;
case GLUT_KEY_LEFT:
speed =0.0f;
//do something here
break;
case GLUT_KEY_RIGHT:
//do something here
break;
}
glutPostRedisplay();
}


void handleKeypress(unsigned char key, int x, int y) {
switch (key) {
case 'a':
speed = 0.0f;
break;
case 'w':
speed = 0.1f;
break;
glutPostRedisplay();
}}
const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
void renderBitmapString(float x, float y, void *font,const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
GLfloat position1 = 0.0f;
GLfloat speed1 =0.007f;
void carmove(int value) {
    if(position1 > 2.4)
        position1 =0.0f;
    position1 += speed1;
	glutPostRedisplay();
	glutTimerFunc(100, carmove, 0);
}
void bird()
{
       int i;

	GLfloat mm=0.182f; GLfloat nn=.801f; GLfloat radiusmm =.01f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mm, nn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(620, 375);
   // glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-420-200)/2,(glutGet(GLUT_SCREEN_HEIGHT)-375)/2);
    //glutCreateWindow("AIUB CAMPUS VIEW");
    glutInit(&argc, argv);
glutInitWindowSize(320, 320);
glutInitWindowPosition(50, 50);
glutCreateWindow("Translation Animation");
glutDisplayFunc(display);

glutTimerFunc(100, update, 0);
glutSpecialFunc(SpecialInput);
glutKeyboardFunc(handleKeypress);
glutMouseFunc(handleMouse);

 glutMainLoop();
return 0;
    //init();
//    glutReshapeFunc(reshape);
//    glutDisplayFunc(Display);
     for( size_t i = 0; i < 1000; ++i )
    {
//        Point pt;
//        pt.x = -50 + (rand() % 100);
//        pt.y = -50 + (rand() % 100);
//        pt.r = 255;
//        pt.g = 255;
//        pt.b = 255;
//        pt.a = 255;
//        points.push_back(pt);
    }
//    glutTimerFunc(100, cloud, 0);
//    glutTimerFunc(100, rain, 0);
    glutTimerFunc(100, carmove, 0);

//    glutKeyboardFunc(handleKeypress);
//    init();
    glutMainLoop();
    return 0;
}
