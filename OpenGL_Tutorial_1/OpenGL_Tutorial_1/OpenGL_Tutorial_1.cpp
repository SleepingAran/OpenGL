#include <Windows.h>
#include <gl\GL.h>
#include <GL\GLU.h>
#include <glut.h>





void myInit()
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500);

}

void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(250, 250, 0);
	glVertex3f(280, 280, 0);
	glVertex3f(250, 400, 0);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(250, 250, 0);
	glVertex3f(220, 280, 0);
	glVertex3f(250, 400, 0);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(250, 250, 0);
	glVertex3f(280, 280, 0);
	glVertex3f(400, 250, 0);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(250, 250, 0);
	glVertex3f(280, 220, 0);
	glVertex3f(400, 250, 0);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(250, 250, 0);
	glVertex3f(280, 220, 0);
	glVertex3f(250, 100, 0);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(250, 250, 0);
	glVertex3f(220, 220, 0);
	glVertex3f(250, 100, 0);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(250, 250, 0);
	glVertex3f(220, 220, 0);
	glVertex3f(100, 250, 0);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(250, 250, 0);
	glVertex3f(220, 280, 0);
	glVertex3f(100, 250, 0);

	glEnd();
	glFlush();

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("UJDM2024 Tutorial 1");
	glutDisplayFunc(mydisplay);

	myInit();
	glutMainLoop();

	return 0;
}