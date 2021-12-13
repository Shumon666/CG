#include<cstdio>

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

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
glTranslatef(position,position2, 0.0f);
DrawCircle(0.0f,0.0f,0.5f,320);

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

int main(int argc, char** argv) {
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
}
