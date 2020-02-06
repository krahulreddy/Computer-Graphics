#include<stdio.h>
#include<GL/glut.h>
#include "circle.c"

#define H 1000
#define W 800

int X = 0, Y = 0, d = 15, fX = 100, fY = -50, wheelX, wheelY, wheelR = 100, drawNew = 0;
int size = 100, position = 500, clear, rotate, rA;

void display()
{
	glPointSize(1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 1, 0.4);
//	glPushMatrix();
	if(!clear)
	{
		// Head
		circle(position, 400 + size, size, 1);
		circle(position + size / 3, 400 + (3 * size / 2), size / 10, 0);
		circle(position - size / 3, 400 + (3 * size / 2), size / 10, 0);
		bresenham(position + size / 3, 400 + (1.95 * size), position + size / 2, 400 + (5 * size / 2));
		bresenham(position - size / 3, 400 + (1.95 * size), position - size / 2, 400 + (5 * size / 2));

		// Body
		glBegin(GL_POLYGON);
		glVertex2i(position + size, 390 + size);
		glVertex2i(position + size, 390 - size);
		glVertex2i(position - size, 390 - size);
		glVertex2i(position - size, 390 + size);
		glEnd();

		// Legs
		glBegin(GL_POLYGON);
		glVertex2i(position - (size / 5), 390 - (size));
		glVertex2i(position - (3 * size / 5), 390 - (size));
		glVertex2i(position - (3 * size / 5), 390 - (3 * size / 2));
		glVertex2i(position - (size / 5), 390 - (3 * size / 2));
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2i(position + (size / 5), 390 - (size));
		glVertex2i(position + (3 * size / 5), 390 - (size));
		glVertex2i(position + (3 * size / 5), 390 - (3 * size / 2));
		glVertex2i(position + (size / 5), 390 - (3 * size / 2));
		glEnd();

		// Hands
		if(rotate)
		{
//			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
				glTranslatef(position + (6 * size / 5) + 10, 390 + size, 0);
				glRotatef(rA, 1, 0, 0);
				glTranslatef(-position - (6 * size / 5) - 10, -390 - size, 0);
//				glOrtho(0, 1, 0, 1, -1, 1);

				glBegin(GL_POLYGON);
				glVertex2i((position + (size) + 10) / 1, (390 - size) / 1);
				glVertex2i((position + (7 * size / 5) + 10) / 1, (390 - size) / 1);
				glVertex2i((position + (7 * size / 5) + 10) / 1, (390 + size) / 1);
				glVertex2i((position + (size) + 10) / 1, (390 + size) / 1);
				glEnd();

			glPopMatrix();

			glPushMatrix();
				glTranslatef(position - (6 * size / 5) + 10, 390 + size, 0);
				glRotatef(rA, 1, 0, 0);
				glTranslatef(-position + (6 * size / 5) - 10, -390 - size, 0);

				glBegin(GL_POLYGON);
				glVertex2i(position - (size) - 10, 390 - size);
				glVertex2i(position - (7 * size / 5) - 10, 390 - size);
				glVertex2i(position - (7 * size / 5) - 10, 390 + size);
				glVertex2i(position - (size) - 10, 390 + size);
				glEnd();
			glPopMatrix();
		}
		else
		{
			glBegin(GL_POLYGON);
			glVertex2i(position + (size) + 10, 390 - size);
			glVertex2i(position + (7 * size / 5) + 10, 390 - size);
			glVertex2i(position + (7 * size / 5) + 10, 390 + size);
			glVertex2i(position + (size) + 10, 390 + size);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex2i(position - (size) - 10, 390 - size);
			glVertex2i(position - (7 * size / 5) - 10, 390 - size);
			glVertex2i(position - (7 * size / 5) - 10, 390 + size);
			glVertex2i(position - (size) - 10, 390 + size);
			glEnd();
		}
	}
//	glPopMatrix();

	glFlush();
}

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

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(H, W);
	glutCreateWindow("Circle Drawing");

//	gluOrtho2D(0, H, 0, W);
	glOrtho(0, H, 0, W, -100, 100);
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glutDisplayFunc(display);
	glutKeyboardFunc(keyPressed);
//	glutMouseFunc(mouse);
	glutTimerFunc(50, update, 0);
	glutMainLoop();
}
