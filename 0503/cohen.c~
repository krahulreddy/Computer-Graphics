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

	glColor3f(1, 0, 0);

	int i;
	for(i = 0; i < cnt; i++)
	{
		float m;
		if(X2[i] != X1[i])
			m = (Y2[i] - Y1[i]) / (X2[i] - X1[i]);
		else
			m = 64000;
		int b1 = bitCode(X1[i], Y1[i]), b2 = bitCode(X2[i], Y2[i]);
		printf("Line %d: \n\t\tP1: %d\t\tP2: %d\n", i + 1, b1, b2);
		int acc = 0;
		while(!acc)
		{
			if(X2[i] != X1[i])
				m = (Y2[i] - Y1[i]) / (X2[i] - X1[i]);
			else
				m = 64000;
			if((b1 | b2) == 0)
			{
				printf("Line is inside\n");
				line(X1[i], Y1[i], X2[i], Y2[i]);
				acc = 1;
			}
			if((b1 & b2) != 0)
			{
				printf("Line is outside\n");
				break;
			}
			else
			{
				printf("Partial\n");
				if(b1 != 0)
				{
					if(b1 & 8)
					{
						int x = (Y1[i] - y_max) / -m + X1[i];
						X1[i] = x;
						Y1[i] = y_max;
					}
					if(b1 & 4)
					{
						int x = (Y1[i] - y_min) / -m + X1[i];
						X1[i] = x;
						Y1[i] = y_min;
					}
					if(b1 & 2)
					{
						int y = (X1[i] - x_min) * m - Y1[i];
						X1[i] = x_min;
						Y1[i] = -y;
					}
					if(b1 & 1)
					{
						int y = (X1[i] - x_max) * m - Y1[i];
						X1[i] = x_max;
						Y1[i] = -y;
					}
				}
				else
				{
					if(b2 & 8)
					{
						int x = (Y2[i] - y_max) / -m + X2[i];
						X2[i] = x;
						Y2[i] = y_max;
					}
					if(b2 & 4)
					{
						int x = (Y2[i] - y_min) / -m + X2[i];
						X2[i] = x;
						Y2[i] = y_min;
					}
					if(b2 & 2)
					{
						int y = (X2[i] - x_min) * m - Y2[i];
						X2[i] = x_min;
						Y2[i] = -y;
					}
					if(b2 & 1)
					{
						int y = (X2[i] - x_max) * m - Y2[i];
						X2[i] = x_max;
						Y2[i] = -y;
					}

				}

				b1 = bitCode(X1[i], Y1[i]);
				b2 = bitCode(X2[i], Y2[i]);
				printf("%d %d %d %d %d %d\n", X1[i], Y1[i], X2[i], Y2[i], b1, b2);
				//line(X1[i], Y1[i], X2[i], Y2[i]);
			}
		}

//-200 -200 200 200 3 0 0 100 100 100 100 100 200 100 200 0 0 -300 -300 600 500 -50 0 -50 500
	
	}
	glFlush();
}


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
