#include<stdio.h>
#include<GL/glut.h>
//#include "circle.c"

#define H 1000
#define W 800


int x_min, y_min, x_max, y_max, cnt, X1[100], Y1[100], X2[100], Y2[100], Z, rA, shape, tx, ty, tz, n;

int bitCode(x, y)
{
	int ans = 0;
	if(x < x_min)
		ans = 2;
	if(x > x_max)
		ans = 1;
	if(y < y_min)
		ans |= 4;
	if(y > y_max)
		ans |= 8;
	return ans;
}

void line(a, b, c, d)
{
	glBegin(GL_LINES);
		glVertex3i(a, b, 0);
		glVertex3i(c, d, 0);
	glEnd();
}

void display()
{
	glPointSize(1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	
	glColor3f(0, 1, 0.4);

	glBegin(GL_POLYGON);
		glVertex3i(x_min, y_min, 0);
		glVertex3i(x_min, y_max, 0);
		glVertex3i(x_max, y_max, 0);
		glVertex3i(x_max, y_min, 0);
	glEnd();

	glColor3f(0, 0, 0);

	int i;
	for(i = 0; i < cnt; i++)
	{
		int b1 = bitCode(X1[i], Y1[i]), b2 = bitCode(X2[i], Y2[i]);
		printf("Line %d: \n\t\tP1: %d\t\tP2: %d\n", i + 1, b1, b2);
		if((b1 | b2) == 0)
		{
			printf("Line is inside\n");
			line(X1[i], Y1[i], X2[i], Y2[i]);
			continue;
		}
		if((b1 & b2) != 0)
		{
			printf("Line is outside\n");
		}
		else
		{
			printf("Partial\n");
//			if(b1 == 8)
//			{
				
		}
	}
	glFlush();
}
/*
void update( int n) {
	if(abs(X - tx) > 2 && abs(Y - ty) > 2 && abs(Z - tz) > 2)
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
	printf("Enter Vertices(x_min, y_min, x_max, y_max): ");
	scanf("%d %d %d %d", &x_min, &y_min, &x_max, &y_max);

	printf("\nEnter the number of lines: ");
	scanf("%d", &cnt);

	int i;
	for(i = 0; i < cnt; i++)
	{
		printf("\nEnter the vertices of line %d: ", i + 1);
		scanf("%d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
	}

	glutInit(&argc, argv);
	glutInitWindowSize(H, W);
	glutCreateWindow("Line Clipping");

//	gluOrtho2D(0, H, 0, W);
	glOrtho(-H/2, H/2, -W/2, W/2, -1000, 1000);
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
	//glMatrixMode(GL_MODELVIEW);

	glutDisplayFunc(display);
/*	glutKeyboardFunc(keyPressed);
	glutMouseFunc(mouse);*/
	//glutTimerFunc(50, update, 0);
	glutMainLoop();
}
