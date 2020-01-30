#include<stdio.h>
#include<GL/glut.h>

#define H 720
#define W 720

void acute_bresenham(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1, dy = y2 - y1;
	int yi = 1;
	if(dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int D = 2 * dy - dx;
	
	glBegin(GL_POINTS);
	int x, y = y1;
	for(x = x1; x < x2; x++)
	{
		glVertex2f(x, y);
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

void obtuse_bresenham(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1, dy = y2 - y1;
	int xi = 1;
	if(dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int D = 2 * dx - dy;
	
	glBegin(GL_POINTS);
	int y, x = x1;
	for(y = y1; y < y2; y++)
	{
		glVertex2f(x, y);
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

void bresenham(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1, dy = y2 - y1;
	if(abs(dy) < abs(dx))
	{
		dx > 0 ? acute_bresenham(x1, y1, x2, y2) : acute_bresenham(x2, y2, x1, y1);
	}
	else
	{
		dy > 0 ? obtuse_bresenham(x1, y1, x2, y2) : obtuse_bresenham(x2, y2, x1, y1);
	}
}

void draw(cx, cy, x, y)
{
	glBegin(GL_POINTS);
	glVertex2i(cx + x, cx + y);
	glVertex2i(cx + x, cx - y);
	glVertex2i(cx - x, cx + y);
	glVertex2i(cx - x, cx - y);
	glVertex2i(cx + y, cx + x);
	glVertex2i(cx + y, cx - x);
	glVertex2i(cx - y, cx + x);
	glVertex2i(cx - y, cx - x);
	glEnd();
}

void circle(cx, cy, r)
{
	int x = 0, y = r, d = 3 - 2 * r;
	while(y >= x)
	{
		printf("%d %d\n", x, y);
		x++;
		if(d <= 0)
		{
			d = d + 4 * x + 6;
		}
		else
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		draw(cx, cy, x, y);
	}
}
void display()
{
	glPointSize(1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	int i, r = 200;

	// Outer Circle
	glColor3f(0.0, 1.0, 0.4);
	circle(0, 0, r);

	// Ground
	glBegin(GL_POINTS);
	for(i = -2 * r; i < 2 * r; i++)
		glVertex2i(i, -r);
	glEnd();

	// Inner circle
	glColor3f(1.0, 0.0, 0.0);
	circle(0, 0, r / 3);

	// Lines
	bresenham(0, r / 3, 0, r);
	bresenham(0, -r / 3, 0, -r);
	bresenham(r / 3, 0, r, 0);
	bresenham(-r / 3, 0, -r, 0);
	//bresenham(, r / 6, r, r);
	

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 800);
	glutCreateWindow("Circle Drawing");

	gluOrtho2D(-1000, 1000, -800, 800);
	glClearColor(0,0,0,1);
	glutDisplayFunc(display);
	glutMainLoop();
}
