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

int x[100], y[100], r, shape, sx, sy, n, s;

void display()
{
	delay(1000);
	glPointSize(1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 0.4);
	if(shape == 1)
	{
		bresenham(x[0], y[0], x[1], y[1]);
		glColor3f(1, 0, 0);
		bresenham(x[0] * sx, y[0] * sy, x[1] * sx, y[1] * sy);		
	}
	if(shape == 2)
	{
		int i;
		glBegin(GL_POLYGON);
		for(i = 0; i < n; i++)
		{
			glVertex2i(x[i], y[i]);
		}
		glEnd();
		for(i = 0; i < n; i++)
		{
			x[i] *= sx;
			y[i] *= sy;
		}
		glColor3f(1, 0, 0);
		glBegin(GL_POLYGON);
		for(i = 0; i < n; i++)
		{
			glVertex2i(x[i], y[i]);
		}
		glEnd();
	}
	if(shape == 3)
	{
		circle(x[0], y[0], r, 0);
		glColor3f(1, 0, 0);
		circle(x[0], y[0], r * s, 0);
	}

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
	printf("Enter Shape for translation(1 ==> Line, 2 ==> Polygon, 3 ==> Circle): ");
	scanf("%d", &t);
	if(t == 1)
	{
		shape = 1;
		printf("Enter initial x1, y1, x2, y2: ");
		scanf("%d %d %d %d", &x[0], &y[0], &x[1], &y[1]);
	}
	else if(t == 2)
	{
		shape = 2;
		printf("Enter number of sides: ");
		int i;
		scanf("%d", &n);
		for(i = 0; i < n; i++)
		{
			printf("Enter x%d, y%d: ", i + 1, i + 1);
			scanf("%d %d", &x[i], &y[i]);
		}
	}
	else if(t == 3)
	{
		shape = 3;
		printf("Enter center and radius: ");
		scanf("%d %d %d", &x[0], &y[0], &r);
	}
	else
	{
		printf("Wrong input!!");
		return 0;
	}
	
	if(t < 3)
	{
		printf("\nEnter scaling vector(sx, sy): ");
		scanf("%d %d", &sx, &sy);
	}
	else
	{
		printf("\nEnter scaling factor(s): ");
		scanf("%d", &s);
	}
		
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
