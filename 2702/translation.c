#include<stdio.h>
#include<GL/glut.h>
//#include "circle.c"

#define H 1000
#define W 800


int X_, Y_, Z_, X, Y, Z, rA, shape, tx, ty, tz, n;

void display()
{
	glPointSize(1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	//glMatrixMode(GL_MODELVIEW);
	

	glPushMatrix();
		glRotatef(50, 1, 1, 1);
		glPushMatrix();
			glColor3f(0, 1, 0);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 0, Y_ + 0,  Z_ + 0);
				glVertex3i(X_ + 0, Y_ + 100, Z_ + 0);
				glVertex3i(X_ + 100, Y_ + 100, Z_ + 0);
				glVertex3i(X_ + 100, Y_ + 0, Z_ + 0);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 0, 0);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 0, Y_ + 0, Z_ + 100);
				glVertex3i(X_ + 0, Y_ + 100, Z_ + 100);
				glVertex3i(X_ + 100, Y_ + 100, Z_ + 100);
				glVertex3i(X_ + 100, Y_ + 0, Z_ + 100);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0, 0, 1);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 0, Y_ + 0, Z_ + 0);
				glVertex3i(X_ + 0, Y_ + 100, Z_ + 0);
				glVertex3i(X_ + 0, Y_ + 100, Z_ + 100);
				glVertex3i(X_ + 0, Y_ + 0, Z_ + 100);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 1, 0.4);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 100, Y_ + 0, Z_ + 0);
				glVertex3i(X_ + 100, Y_ + 100, Z_ + 0);
				glVertex3i(X_ + 100, Y_ + 100, Z_ + 100);
				glVertex3i(X_ + 100, Y_ + 0, Z_ + 100);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0, 0.5, 0.3);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 0, Y_ + 0, Z_ + 0);
				glVertex3i(X_ + 100, Y_ + 0, Z_ + 0);
				glVertex3i(X_ + 100, Y_ + 0, Z_ + 100);
				glVertex3i(X_ + 0, Y_ + 0, Z_ + 100);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 1, 1);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 0, Y_ + 100, Z_ + 0);
				glVertex3i(X_ + 100, Y_ + 100, Z_ + 0);
				glVertex3i(X_ + 100, Y_ + 100, Z_ + 100);
				glVertex3i(X_ + 0, Y_ + 100, Z_ + 100);
			glEnd();
		glPopMatrix();
	glPopMatrix();
	

	glPushMatrix();
		glRotatef(50, 1, 1, 1);
		glPushMatrix();
			glColor3f(0, 1, 0);
			glBegin(GL_POLYGON);
				glVertex3i(X + 0, Y + 0,  Z + 0);
				glVertex3i(X + 0, Y + 100, Z + 0);
				glVertex3i(X + 100, Y + 100, Z + 0);
				glVertex3i(X + 100, Y + 0, Z + 0);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 0, 0);
			glBegin(GL_POLYGON);
				glVertex3i(X + 0, Y + 0, Z + 100);
				glVertex3i(X + 0, Y + 100, Z + 100);
				glVertex3i(X + 100, Y + 100, Z + 100);
				glVertex3i(X + 100, Y + 0, Z + 100);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0, 0, 1);
			glBegin(GL_POLYGON);
				glVertex3i(X + 0, Y + 0, Z + 0);
				glVertex3i(X + 0, Y + 100, Z + 0);
				glVertex3i(X + 0, Y + 100, Z + 100);
				glVertex3i(X + 0, Y + 0, Z + 100);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 1, 0.4);
			glBegin(GL_POLYGON);
				glVertex3i(X + 100, Y + 0, Z + 0);
				glVertex3i(X + 100, Y + 100, Z + 0);
				glVertex3i(X + 100, Y + 100, Z + 100);
				glVertex3i(X + 100, Y + 0, Z + 100);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0, 0.5, 0.3);
			glBegin(GL_POLYGON);
				glVertex3i(X + 0, Y + 0, Z + 0);
				glVertex3i(X + 100, Y + 0, Z + 0);
				glVertex3i(X + 100, Y + 0, Z + 100);
				glVertex3i(X + 0, Y + 0, Z + 100);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 1, 1);
			glBegin(GL_POLYGON);
				glVertex3i(X + 0, Y + 100, Z + 0);
				glVertex3i(X + 100, Y + 100, Z + 0);
				glVertex3i(X + 100, Y + 100, Z + 100);
				glVertex3i(X + 0, Y + 100, Z + 100);
			glEnd();
		glPopMatrix();
	glPopMatrix();
	glFlush();
}

void update( int n) {
	if(abs(X - tx) > 5 && abs(Y - ty) > 5 && abs(Z - tz) > 5)
	{
		printf("%d %d %d\n", X, Y, Z);
		X += (tx - X) / 100;
		Y += (ty - Y) / 100;
		Z += (tz - Y) / 100;
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
	printf("\nEnter translation vector(tx, ty, tz): ");
	scanf("%d %d %d", &tx, &ty, &tz);

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
	glutTimerFunc(50, update, 0);
	glutMainLoop();
}
