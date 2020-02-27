#include<stdio.h>
#include<GL/glut.h>
#include "math.h"
#include <stdlib.h>

#define H 1000
#define W 800


int rotMode, X_, Y_, Z_, X, Y, Z, rA, size_ = 100, size = 100, tx, ty, tz, n;
double theta;

void display()
{
	glPointSize(1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	
	int XArray[] = {X_, X_, X_ + size, X_ + size, X_, X_, X_ + size, X_ + size, X_, X_, X_, X_, X_ + size, X_ + size, X_ + size, X_ + size, X_, X_ + size, X_ + size, X_, X_, X_ + size, X_ + size, X_};
	int YArray[] = {Y_, Y_ + size, Y_ + size, Y_, Y_, Y_ + size, Y_ + size, Y_, Y_, Y_ + size, Y_ + size, Y_, Y_, Y_ + size, Y_ + size, Y_, Y_, Y_, Y_, Y_, Y_ + size, Y_ + size, Y_ + size, Y_ + size};
	int ZArray[] = {Z_, Z_, Z_, Z_, Z_ + size, Z_ + size, Z_ + size, Z_ + size, Z_, Z_, Z_ + size, Z_ + size, Z_, Z_, Z_ + size, Z_ + size, Z_, Z_, Z_ + size, Z_ + size, Z_, Z_, Z_ + size, Z_ + size};

	glPushMatrix();
		glRotatef(50, 0, 1, 1);
		glPushMatrix();
			glColor3f(0, 1, 0);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 0, Y_ + 0,  Z_ + 0);
				glVertex3i(X_ + 0, Y_ + size_, Z_ + 0);
				glVertex3i(X_ + size_, Y_ + size_, Z_ + 0);
				glVertex3i(X_ + size_, Y_ + 0, Z_ + 0);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 0, 0);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 0, Y_ + 0, Z_ + size_);
				glVertex3i(X_ + 0, Y_ + size_, Z_ + size_);
				glVertex3i(X_ + size_, Y_ + size_, Z_ + size_);
				glVertex3i(X_ + size_, Y_ + 0, Z_ + size_);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0, 0, 1);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 0, Y_ + 0, Z_ + 0);
				glVertex3i(X_ + 0, Y_ + size_, Z_ + 0);
				glVertex3i(X_ + 0, Y_ + size_, Z_ + size_);
				glVertex3i(X_ + 0, Y_ + 0, Z_ + size_);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 1, 0.4);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + size_, Y_ + 0, Z_ + 0);
				glVertex3i(X_ + size_, Y_ + size_, Z_ + 0);
				glVertex3i(X_ + size_, Y_ + size_, Z_ + size_);
				glVertex3i(X_ + size_, Y_ + 0, Z_ + size_);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0, 0.5, 0.3);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 0, Y_ + 0, Z_ + 0);
				glVertex3i(X_ + size_, Y_ + 0, Z_ + 0);
				glVertex3i(X_ + size_, Y_ + 0, Z_ + size_);
				glVertex3i(X_ + 0, Y_ + 0, Z_ + size_);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 1, 1);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 0, Y_ + size_, Z_ + 0);
				glVertex3i(X_ + size_, Y_ + size_, Z_ + 0);
				glVertex3i(X_ + size_, Y_ + size_, Z_ + size_);
				glVertex3i(X_ + 0, Y_ + size_, Z_ + size_);
			glEnd();
		glPopMatrix();
	glPopMatrix();

//	X += 200;
//	Y += 200;
//	Z += 200;
	int i;
	for(i = 0; i < 24; i++)
	{
		//printf("%d, %d, %d, %d\n", XArray[i], YArray[i], (int)((double)XArray[i] * (double)cos(theta) - (double)YArray[i] * (double)sin(theta)), (int)((double)XArray[i] * (double)sin(theta) + (double)YArray[i] * (double)cos(theta)));
//		printf("%d, %d, %lf, %lf, %lf\n", XArray[i], YArray[i], (double)cos(theta), (double)sin(theta), theta);
	
		if(rotMode == 1)
		{
			int t = (int)XArray[i] * (double)cos(theta) - (double)YArray[i] * (double)sin(theta);
			YArray[i] = (int)((double)XArray[i] * (double)sin(theta)) + ((double)YArray[i] * (double)cos(theta));
			XArray[i] = t;
		}
		else if(rotMode == 2)
		{
			int t = (int)XArray[i] * (double)cos(theta) - (double)ZArray[i] * (double)sin(theta);
			ZArray[i] = (int)((double)XArray[i] * (double)sin(theta)) + ((double)ZArray[i] * (double)cos(theta));
			XArray[i] = t;
		}
		else
		{
			int t = (int)ZArray[i] * (double)cos(theta) - (double)YArray[i] * (double)sin(theta);
			YArray[i] = (int)((double)ZArray[i] * (double)sin(theta)) + ((double)YArray[i] * (double)cos(theta));
			ZArray[i] = t;
		}
	}
	glPushMatrix();
		glRotatef(50, 0, 1, 1);
		glBegin(GL_POINTS);
		for(i = 0; i < 24; i++)
		{
			if(i % 4 == 0)
			{
				glColor3f((double)rand() / (double)RAND_MAX, (double)rand() / (double)RAND_MAX, (double)rand() / (double)RAND_MAX);
				glEnd();
				glBegin(GL_POLYGON);
			}
			glVertex3i(XArray[i], YArray[i], ZArray[i]);
			printf("%d, %d, %d\n", XArray[i], YArray[i], ZArray[i]);
			//if(i % 4 == 0 && i != 0)
					
		}
		glEnd();
	glPopMatrix();
/*
	glPushMatrix();
		glRotatef(rA, 1, 1, 1);
		glPushMatrix();
			glColor3f(0, 1, 0);
			glBegin(GL_POLYGON);
				glVertex3i(X + 0, Y + 0,  Z + 0);
				glVertex3i(X + 0, Y + size, Z + 0);
				glVertex3i(X + size, Y + size, Z + 0);
				glVertex3i(X + size, Y + 0, Z + 0);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 0, 0);
			glBegin(GL_POLYGON);
				glVertex3i(X + 0, Y + 0, Z + size);
				glVertex3i(X + 0, Y + size, Z + size);
				glVertex3i(X + size, Y + size, Z + size);
				glVertex3i(X + size, Y + 0, Z + size);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0, 0, 1);
			glBegin(GL_POLYGON);
				glVertex3i(X + 0, Y + 0, Z + 0);
				glVertex3i(X + 0, Y + size, Z + 0);
				glVertex3i(X + 0, Y + size, Z + size);
				glVertex3i(X + 0, Y + 0, Z + size);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 1, 0.4);
			glBegin(GL_POLYGON);
				glVertex3i(X + size, Y + 0, Z + 0);
				glVertex3i(X + size, Y + size, Z + 0);
				glVertex3i(X + size, Y + size, Z + size);
				glVertex3i(X + size, Y + 0, Z + size);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0, 0.5, 0.3);
			glBegin(GL_POLYGON);
				glVertex3i(X + 0, Y + 0, Z + 0);
				glVertex3i(X + size, Y + 0, Z + 0);
				glVertex3i(X + size, Y + 0, Z + size);
				glVertex3i(X + 0, Y + 0, Z + size);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 1, 1);
			glBegin(GL_POLYGON);
				glVertex3i(X + 0, Y + size, Z + 0);
				glVertex3i(X + size, Y + size, Z + 0);
				glVertex3i(X + size, Y + size, Z + size);
				glVertex3i(X + 0, Y + size, Z + size);
			glEnd();
		glPopMatrix();
	glPopMatrix();*/
	glFlush();
}

void update( int n) {
	if(size < tx * size_)
	{
		printf("%d %d %d\n", X, Y, Z);
		size += 1;
	}
//	X += 2;
	rA ++;
	glutPostRedisplay();
	glutTimerFunc(10, update, 0);
}
/*
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
	/*printf("Enter Shape for translation(1 ==> Line, 2 ==> Polygon, 3 ==> Circle): ");
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
*/
	printf("\nEnter axis and rotation angle theta: ");
	scanf("%d %lf", &rotMode, &theta);
	theta = theta *(double)3.14 / (double)180;
	glutInit(&argc, argv);
	glutInitWindowSize(H, W);
	glutCreateWindow("Circle Drawing");

//	gluOrtho2D(0, H, 0, W);
	glOrtho(-H/2, H/2, -W/2, W/2, -500, 500);
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glutDisplayFunc(display);
/*	glutKeyboardFunc(keyPressed);
	glutMouseFunc(mouse);*/
	//glutTimerFunc(50, update, 0);
	glutMainLoop();
}
