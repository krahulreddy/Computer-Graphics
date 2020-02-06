#include<stdio.h>
#include<GL/glut.h>

#define H 720
#define W 720

int X = 0, rA = 0;

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

void draw(cx, cy, x, y, semi)
{
	glBegin(GL_POINTS);
	glVertex2i(cx + x, cy + y);
	glVertex2i(cx - x, cy + y);
	glVertex2i(cx + y, cy + x);
	glVertex2i(cx - y, cy + x);
	if(!semi)
	{
		glVertex2i(cx - y, cy - x);
		glVertex2i(cx + y, cy - x);
		glVertex2i(cx - x, cy - y);
		glVertex2i(cx + x, cy - y);
	}
	glEnd();
}

void circle(cx, cy, r, semi)
{
	int x = 0, y = r, d = 3 - 2 * r;
	while(y >= x)
	{
//		printf("%d %d\n", x, y);
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
		draw(cx, cy, x, y, semi);
	}
}

void wheel(cx, cy, r)
{
	int i;
	// Outer Circle
	glColor3f(0.0, 1.0, 0.4);
	circle(cx, cy, r, 0);

	// Inner circle
	glColor3f(1.0, 0.0, 0.0);
	circle(cx, cy, r / 3, 0);

	// Lines		
	bresenham(cx, cy + r / 3, cx, cy + r);
	bresenham(cx, cy - r / 3, cx, cy - r);
	bresenham(cx + r / 3, cy, cx + r, cy);
	bresenham(cx - r / 3, cy, cx - r, cy);

	bresenham(cx + r / 3 / 1.4, cy + r / 3 / 1.4, cx + r / 1.4, cy + r / 1.4);
	bresenham(cx + r / 3 / 1.4, cy - r / 3 / 1.4, cx + r / 1.4, cy - r / 1.4);
	bresenham(cx - r / 3 / 1.4, cy + r / 3 / 1.4, cx - r / 1.4, cy + r / 1.4);
	bresenham(cx - r / 3 / 1.4, cy - r / 3 / 1.4, cx - r / 1.4, cy - r / 1.4);
}
void display()
{
	glPointSize(1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	int wheelSize = 200, wheelDistance = 300;

	// Ground
	int i = 0;
	glBegin(GL_POINTS);
	for(i = -2000; i < 2000; i++)
		glVertex2i(i, -wheelSize);

	glEnd();
	glPushMatrix();
		glTranslatef(-wheelDistance + X, 0, 0);
		glRotatef(-rA, 0, 0, 1);
		glTranslatef(wheelDistance - X, 0, 0);
		wheel(-wheelDistance + X, 0, wheelSize);
	glPopMatrix();
	glTranslatef(0, 0, 0);
	glPushMatrix();
		glTranslatef(wheelDistance + X, 0, 0);
		glRotatef(-rA, 0, 0, 1);
		glTranslatef(-wheelDistance - X, 0, 0);
		wheel(wheelDistance + X, 0, wheelSize);
	glPopMatrix();

	int edge = wheelDistance + wheelSize;
	// Car Body
	bresenham(X, edge, -750 + X, wheelDistance);
	bresenham(-750 + X, wheelDistance, -700 + X, 0);
	bresenham(-520 + X, 0, -700 + X, 0);
	circle(-wheelDistance + X, 0, 220, 1);
	bresenham(-80 + X, 0, 80 + X, 0);
	circle(wheelDistance + X, 0, 220, 1);
	bresenham(520 + X, 0, 700 + X, 0);
	bresenham(700 + X, 0, 700 + X, wheelSize);
	bresenham(700 + X, wheelSize, X, 500);

	glFlush();
}

void update( int n) {
	X += 2;
	rA ++;
//	glRotatef(10, 0, 0, 1);
	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 800);
	glutCreateWindow("Circle Drawing");

	gluOrtho2D(-1000, 1000, -800, 800);
	glClearColor(0,0,0,1);
	glutDisplayFunc(display);
	glutTimerFunc(50, update, 0);
	glutMainLoop();
}
