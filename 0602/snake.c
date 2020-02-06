#include<stdio.h>
#include<GL/glut.h>

#define H 1000
#define W 800

int X = 0, Y = 0, d = 15, fX = 100, fY = -50;

void display()
{
	glPointSize(1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Character
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2i(X, Y);
	glVertex2i(X, Y + 50);
	glVertex2i(X + 50, Y + 50);
	glVertex2i(X + 50, Y);
	glEnd();
	
	// Food
	glColor3f(0, 1, 0.4);
	glBegin(GL_POLYGON);
	glVertex2i(fX, fY);
	glVertex2i(fX, fY + 50);
	glVertex2i(fX + 50, fY + 50);
	glVertex2i(fX + 50, fY);
	glEnd();

	glFlush();
}

void update( int n) {
//	X += 2;
//	rA ++;
	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}


void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN)
			glutIdleFunc(spinDisplay);
		break;
	case GLUT_MIDDLE_BUTTON:
		if(state==GLUT_DOWN)
		{
			glutIdleFunc(NULL);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if(state==GLUT_DOWN)
			glutIdleFunc(spinDisplayReverse);
		break;
	default:
		break;
	}
}

void keyPressed(unsigned char key, int x, int y)
{
	if(key == 'a')
	{
		X -= d;
	}
	else if(key == 's')
	{
		Y -= d;
	}
	else if(key == 'd')
	{
		X += d;
	}
	else if(key == 'w')
	{
		Y += d;
	}
	if(abs(X - fX) < 50 && abs(Y - fY) < 50)
	{
		fX = rand() % H > H / 2? rand() % H : -rand() % H;
		fY = rand() % W > W / 2? rand() % W : -rand() % W;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(H, W);
	glutCreateWindow("Circle Drawing");

	gluOrtho2D(-H, H, -W, W);
	glClearColor(0,0,0,1);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyPressed);
//	glutTimerFunc(50, update, 0);
	glutMainLoop();
}
