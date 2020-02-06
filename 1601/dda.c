#include<stdio.h>
#include<GL/glut.h>
//#include<math.h>
#define pi 3.14

#define H 600
#define W 720

void dda(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1, dy = y2 - y1, steps, Xinc, Yinc;
	if(abs(dx) > abs(dy))
	{
		steps = abs(dx);
	}
	else
	{
		steps = abs(dy);
	}
	Xinc = dx / (float) steps;
	Yinc = dy / (float) steps;
//	printf("%f, %f\n", Xinc, Yinc);
	glBegin(GL_POINTS);
	float v, x = x1, y = y1;
	for(v = 0; v < steps; v++)
	{
		x = x + Xinc;
		y = y + Yinc;
		glVertex2f(x / W, y / H);
//		printf("%d, %d\n", x, y);
	}
	glEnd();
}



void acute_bresenham(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1, dy = y2 - y1;
	float yi = 1;
	if(dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	float D = 2 * dy - dx;
	
	glBegin(GL_POINTS);
	float x, y = y1;
	for(x = x1; x < x2; x++)
	{
		glVertex2f(x / W, y / H);
		if(D > 0)
		{
			y = y + yi;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
//		printf("%d, %d\n", x, y);
	}
	glEnd();
}

void obtuse_bresenham(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1, dy = y2 - y1;
	float xi = 1;
	if(dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	float D = 2 * dx - dy;
	
	glBegin(GL_POINTS);
	float y, x = x1;
	for(y = y1; y < y2; y++)
	{
		glVertex2f(x / W, y / H);
		if(D > 0)
		{
			x = x + xi;
			D = D - 2 * dy;
		}
		D = D + 2 * dx;
//		printf("%d, %d\n", x, y);
	}
	glEnd();
}

void bresenham(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1, dy = y2 - y1;
	if(abs(dy) < abs(dx))
	{
		dx > 0 ? acute_bresenham(x1, y1, x2, y2) : acute_bresenham(x2, y2, x1, y1);
	}
	else
	{
		dy > 0 ? obtuse_bresenham(x1, y1, x2, y2) : obtuse_bresenham(x2, y2, x1, y1);
	}
}

		

void display()
{
	glPointSize(1.0);
	glColor3f(0.0, 1.0, 0.4);
	glClear(GL_COLOR_BUFFER_BIT);
	//dda(0, 0, 100, 100);
	//dda(-100, 50, 200, -100);

	glColor3f(1.0, 0.0, 0.4);

	bresenham(100, 100, -100, 100);
	bresenham(100, 100, 100, -100);
	bresenham(-100, -100, -100, 100);
	bresenham(-100, -100, 100, -100);

	glColor3f(0.0, 1.0, 0.4);

	bresenham(0, 100, 100, 0);
	bresenham(0, 100, -100, 0);
	bresenham(0, -100, 100, 0);
	bresenham(0, -100, -100, 0);

	glColor3f(1.0, 0.4, 0.0);
	
	bresenham(50, 50, -50, 50);
	bresenham(50, 50, 50, -50);
	bresenham(-50, -50, -50, 50);
	bresenham(-50, -50, 50, -50);

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(W, H);
	glutCreateWindow("W");

	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	glutDisplayFunc(display);
	glutMainLoop();
}
