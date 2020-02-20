#include<stdio.h>
#include<GL/glut.h>
#include "circle.c"

#define H 1000
#define W 800

void delay(int mil)
{
	long long int i = 0;
	while(i++ < 10000 * mil)
	;
}

int x[100], y[100], r, axis, tx, ty, n;

void display()
{
	delay(1000);
	glPointSize(1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 0.4);

	int i;
	glBegin(GL_POLYGON);
	for(i = 0; i < n; i++)
	{
		glVertex2i(x[i], y[i]);
	}
	glEnd();
	for(i = 0; i < n; i++)
	{
		if(axis == 2)
			x[i] = -x[i];
		if(axis == 1)
			y[i] = -y[i];
	}
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	for(i = 0; i < n; i++)
	{
		glVertex2i(x[i], y[i]);
	}
	glEnd();
	glFlush();
}
/*
void update( int n) {
//	X += 2;
	rA ++;
	glutPostRedisplay();
	glutTimerFunc(10, update, 0);
}

void keyPressed(unsigned char key, int x, int y)
{
	if(key == 'r')
	{
		rA = 0;
		rotate = 1;// Rotate hands
	}
	else if(key == 's')
	{
		rotate = 0;// Stop hand rotation
	}
	else if(key == 'i')
	{
		size += d;
	}
	else if(key == 'd')
	{
		size -= d;
		if(size < 0)
			size = 0;
	}
	else if(key == 't')
	{
		position += d;
		if(size < 0)
			size = 0;
	}
	else if(key == 'h')
	{
		position -= d;
		if(size < 0)
			size = 0;
	}
	else if(key == 'c')
	{
		clear = !clear;
		glClear(GL_COLOR_BUFFER_BIT);
	}
	else if(key == 'e')
	{
		printf("Exit\n");
		glutDestroyWindow(1);
		exit;
	}
	glutPostRedisplay();
}
*/
int main(int argc, char** argv)
{
	int t;
	printf("Enter number of sides: ");
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		printf("Enter x%d, y%d: ", i + 1, i + 1);
		scanf("%d %d", &x[i], &y[i]);
	}
	printf("Enter Axis for reflection(1 ==> X, 2 ==> Y): ");
	scanf("%d", &axis);

	glutInit(&argc, argv);
	glutInitWindowSize(H, W);
	glutCreateWindow("Circle Drawing");

//	gluOrtho2D(0, H, 0, W);
	glOrtho(-H/2, H/2, -W/2, W/2, -100, 100);
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glutDisplayFunc(display);
/*	glutKeyboardFunc(keyPressed);
	glutMouseFunc(mouse);
	glutTimerFunc(50, update, 0);*/
	glutMainLoop();
}
