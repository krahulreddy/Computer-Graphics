#include <GL/glut.h>
#include <math.h>

#define pi 3.14

int l = 0, t = 50, q = 550, qt = 1;

void displayCB(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.5, 0.5, 0.5);	//Mountain
  glBegin(GL_TRIANGLES);

  glVertex2i(-300, 100);
  glVertex2i(400, 100);
  glVertex2i(0, 400);

  glVertex2i(0, 100);
  glVertex2i(400, 100);
  glVertex2i(200, 400);

  glVertex2i(200, 100);
  glVertex2i(600, 100);
  glVertex2i(400, 400);

  glVertex2i(400, 100);
  glVertex2i(800, 100);
  glVertex2i(600, 450);

  glVertex2i(700, 100);
  glVertex2i(1100, 100);
  glVertex2i(900, 400);
  glEnd();

  int lhHeight = 250, lhWidth = 50, lhStartx = 50, lhStarty = 50;
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_POLYGON);		//LH tower
  glVertex2i(lhStartx, lhStarty);
  glVertex2i(lhStartx, lhStarty + lhHeight);
  glVertex2i(lhStartx + lhWidth, lhStarty + lhHeight);
  glVertex2i(lhStartx + lhWidth, lhStarty);
  glEnd();

  glColor3f(1.0, 1.0, 1.0);	//LH White
  int wh = lhHeight / 5;
  glBegin(GL_POLYGON);
  glVertex2i(lhStartx, lhStarty + wh);
  glVertex2i(lhStartx, lhStarty + 2 * wh);
  glVertex2i(lhStartx + lhWidth, lhStarty + 2 * wh);
  glVertex2i(lhStartx + lhWidth, lhStarty + wh);
  glEnd();
  glBegin(GL_POLYGON);
  glVertex2i(lhStartx, lhStarty + 3 * wh);
  glVertex2i(lhStartx, lhStarty + 4 * wh);
  glVertex2i(lhStartx + lhWidth, lhStarty + 4 * wh);
  glVertex2i(lhStartx + lhWidth, lhStarty + 3 * wh);
  glEnd();

  glColor3f(0.0, 1.0, 1.0);	//Light
  glBegin(GL_POLYGON);
  glVertex2i(l, 0);
  glVertex2i(l + 50, 0);
  glVertex2i(lhStartx + lhWidth / 2, lhStarty + lhHeight * 11 / 10);
  glEnd();

  glColor3f(0.5, 1.0, 1.0);	//Top Light
  glBegin(GL_POLYGON);
  float x, y;
  for(float i = 0; i < 2 * pi; i += 0.01)
  {
    x = 20 * sin(i);
    y = 20 * cos(i);
    glVertex2i(lhStartx + lhWidth / 2 + x, lhStarty + lhHeight * 11 / 10 + y);
  }
  glEnd();
  
  glColor3f(1.0, 1.0, 1.0);	//Moon
  glBegin(GL_POLYGON);
  for(float i = 0; i < 2 * pi; i += 0.01)
  {
    x = 50 * sin(i);
    y = 50 * cos(i);
    glVertex2i(600 + x, 600 + y);
  }
  glEnd();
  glColor3f(0.0, 0.0, 0.0);	//Moon
  glBegin(GL_POLYGON);
  for(float i = 0; i < 2 * pi; i += 0.01)
  {
    x = 50 * sin(i);
    y = 50 * cos(i);
    glVertex2i(q + x, 600 + y);
  }
  glEnd();

  glFlush();  
}


void update( int n) {
	if(l >= 800 || l < 0)
		t = -t;
        if(q >= 700 || q < 500)
		qt = -qt;
	l += t;
	q += qt;
	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}

int main(int argc, char *argv[])
{
  int win;

  glutInit(&argc, argv);		/* initialize GLUT system */

  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(800,800);
  win = glutCreateWindow("Triangle");	/* create window */

  /* from this point on the current window is win */

  glClearColor(0.0,0.0,0.0,0.0);	/* set background to black */
  gluOrtho2D(0,800,0,800);		/* how object is mapped to window */
  glutDisplayFunc(displayCB);		/* set window's display callback */
  glutTimerFunc(50, update, 0);
  glutMainLoop();			/* start processing events... */

  /* execution never reaches this point */

  return 0;
}
