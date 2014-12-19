// Winter in MTL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<glut.h>
#include<freeglut.h>
#include<ctime>
#include "curb.h"

using namespace std;

void initialize();
void draw();
void drawTop(int i);
void drawMiddle(int i);
void drawBottom(int i);
void drawLedgend();
void drawPerson();
void action(int key, int x, int y);
void Timer(int value);
void check();

curb sidewalk;

char *numbers = { "0123456789" };
char *salt = { "salt = " };
char *ice = { "ice = " };
char *died = { "You slipped on ice and died." };

bool dead = false;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Winter in MTL");

	initialize();

	glutDisplayFunc(draw);
	glutSpecialFunc(action);
	glutTimerFunc(700, Timer, 0);

	glutMainLoop();

	return 0;
}

void initialize()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, 10, 0, 4);
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 10; i++)
	{
		glPushMatrix();
		glTranslatef(i, 2, 0);
		drawTop(i);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(i, 1, 0);
		drawMiddle(i);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(i, 0, 0);
		drawBottom(i);
		glPopMatrix();
	}
	
	drawLedgend();
	drawPerson();

	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();
}

void drawTop(int i)
{
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(0, 0);
		glVertex2f(1, 0);
		glVertex2f(1, 1);
		glVertex2f(0, 1);
	glEnd();
	
	if (sidewalk.top[i] == 1)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_QUADS);
			glVertex2f(0, 0);
			glVertex2f(1, 0);
			glVertex2f(1, 1);
			glVertex2f(0, 1);
		glEnd();
	}
	else if (sidewalk.top[i] == 2)
	{
		glColor3f(0, 0, 0);
		glBegin(GL_QUADS);
			glVertex2f(0.25, 0.25);
			glVertex2f(0.75, 0.25);
			glVertex2f(0.75, 0.75);
			glVertex2f(0.25, 0.75);
		glEnd();
	}
}

void drawMiddle(int i)
{
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(0, 0);
		glVertex2f(1, 0);
		glVertex2f(1, 1);
		glVertex2f(0, 1);
	glEnd();
	
	if (sidewalk.middle[i] == 1)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_QUADS);
			glVertex2f(0, 0);
			glVertex2f(1, 0);
			glVertex2f(1, 1);
			glVertex2f(0, 1);
		glEnd();
	}
	else if (sidewalk.middle[i] == 2)
	{
		glColor3f(0, 0, 0);
		glBegin(GL_QUADS);
			glVertex2f(0.25, 0.25);
			glVertex2f(0.75, 0.25);
			glVertex2f(0.75, 0.75);
			glVertex2f(0.25, 0.75);
		glEnd();
	}
}

void drawBottom(int i)
{
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(0, 0);
		glVertex2f(1, 0);
		glVertex2f(1, 1);
		glVertex2f(0, 1);
	glEnd();

	if (sidewalk.bottom[i] == 1)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_QUADS);
			glVertex2f(0, 0);
			glVertex2f(1, 0);
			glVertex2f(1, 1);
			glVertex2f(0, 1);
		glEnd();
	}
	else if (sidewalk.bottom[i] == 2)
	{
		glColor3f(0, 0, 0);
		glBegin(GL_QUADS);
			glVertex2f(0.25, 0.25);
			glVertex2f(0.75, 0.25);
			glVertex2f(0.75, 0.75);
			glVertex2f(0.25, 0.75);
		glEnd();
	}
}

void drawLedgend()
{
	glColor3f(0, 0, 0);

	if (dead)
	{
		glRasterPos2f(2, 3.2);

		for (int i = 0; i < 28; i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, died[i]);
		}
	}
	
	glRasterPos2f(0.5, 3.4);

	for (int i = 0; i < 7; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, salt[i]);
	}

	if (sidewalk.salt < 10)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[sidewalk.salt]);
	}
	else
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[sidewalk.salt / 10]);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[sidewalk.salt % 10]);
	}
	
	glRasterPos2f(6.5, 3.4);

	for (int i = 0; i < 7; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, salt[i]);
	}

	glPushMatrix();
	glTranslatef(7, 3, 0);
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
		glVertex2f(0.25, 0.25);
		glVertex2f(0.75, 0.25);
		glVertex2f(0.75, 0.75);
		glVertex2f(0.25, 0.75);
	glEnd();
	glPopMatrix();

	glRasterPos2f(8.5, 3.4);

	for (int i = 0; i < 6; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ice[i]);
	}

	glPushMatrix();
	glTranslatef(9, 3, 0);
	glColor3f(0, 0, 1);
	glBegin(GL_QUADS);
		glVertex2f(0.25, 0.25);
		glVertex2f(0.75, 0.25);
		glVertex2f(0.75, 0.75);
		glVertex2f(0.25, 0.75);
	glEnd();
	glPopMatrix();
}

void drawPerson()
{
	glPushMatrix();
	glTranslatef(0, sidewalk.pos, 0);
	glColor3f(0.6, 0, 1);
	glBegin(GL_QUADS);
		glVertex2f(0.25, 0.25);
		glVertex2f(0.75, 0.25);
		glVertex2f(0.75, 0.75);
		glVertex2f(0.25, 0.75);
	glEnd();
	glPopMatrix();
}

void Timer(int value)
{
	if (!dead)
	{
		sidewalk.top.erase(sidewalk.top.begin());
		sidewalk.middle.erase(sidewalk.middle.begin());
		sidewalk.bottom.erase(sidewalk.bottom.begin());

		sidewalk.add();

		check();

		glutTimerFunc(500, Timer, 0);
	}
}

void action(int key, int x, int y)
{
	if (key == GLUT_KEY_RIGHT)
	{
		if (sidewalk.salt != 0)
		{
			sidewalk.salt--;
			switch (sidewalk.pos)
			{
			case(0) :
				sidewalk.bottom[1] = 0;
				break;
			case(1) :
				sidewalk.middle[1] = 0;
				break;
			case(2) :
				sidewalk.top[1] = 0;
				break;
			default:
				break;
			}
		}
	}
	else if (key == GLUT_KEY_UP)
	{
		if (sidewalk.pos != 2)
		{
			sidewalk.pos++;
		}
	}
	else if (key == GLUT_KEY_DOWN)
	{
		if (sidewalk.pos != 0)
		{
			sidewalk.pos--;
		}
	}

	check();
	glutPostRedisplay();
}

void check()
{
	switch (sidewalk.pos)
	{
	case(0) :
		if (sidewalk.bottom[0] == 1)
		{
			dead = true;
		}
		else if (sidewalk.bottom[0] == 2)
		{
			sidewalk.salt++;
			sidewalk.bottom[0] = 0;
		}
		else
		{

		}
		break;
	case(1) :
		if (sidewalk.middle[0] == 1)
		{
			dead = true;
		}
		else if (sidewalk.middle[0] == 2)
		{
			sidewalk.salt++;
			sidewalk.middle[0] = 0;
		}
		else
		{

		}
		break;
	case(2) :
		if (sidewalk.top[0] == 1)
		{
			dead = true;
		}
		else if (sidewalk.top[0] == 2)
		{
			sidewalk.salt++;
			sidewalk.top[0] = 0;
		}
		else
		{

		}
		break;
	default:
		break;
	}
}
