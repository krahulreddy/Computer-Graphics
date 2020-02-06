#include<stdio.h>
#include<GL/glut.h>
#include "circle.c"

#define H 1000
#define W 800

int X = 0, Y = 0, d = 15, fX = 100, fY = -50, wheelX, wheelY, wheelR = 100, drawNew = 0;

void display()
{
	glPointSize(1.0);
	//glClear(GL_COLOR_BUFFER_BIT);

/*	if(drawNew)
	{
		wheel(wheelX, wheelY, wheelR);
		drawNew = 0;
		printf("%d %d\n", wheelX, wheelY);
	}
/*	// Character
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
*/
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
		wheelX = x;
		wheelY = W - y;
		wheel(x, W - y, wheelR);
		printf("%d %d\n", x, y);
		break;
	case GLUT_RIGHT_BUTTON:
		printf("Exit\n");
		glutDestroyWindow(1);
		exit;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

/*
switch(button)
	{
		case GLUT_LEFT_BUTTON:
			wheel(x, y, wheelR);
			break;
		case GLUT_RIGHT_BUTTON:
			exit 1;
		default:
			break;
	}
*/
void keyPressed(unsigned char key, int x, int y)
{
	if(key == 'i')
	{
		wheelR += d;
	}
	else if(key == 'd')
	{
		wheelR -= d;
		if(wheelR < 0)
			wheelR = d;
	}
	else if(key == 'c')
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

/*
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
*/
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(H, W);
	glutCreateWindow("Circle Drawing");

	gluOrtho2D(0, H, 0, W);
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glutDisplayFunc(display);
	glutKeyboardFunc(keyPressed);
	glutMouseFunc(mouse);
//	glutTimerFunc(50, update, 0);
	glutMainLoop();
}
