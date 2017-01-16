#include<Windows.h>
#include<GL\GL.h>
#include <gl\GLU.h>
#include <glut.h>

void myInit()
{
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500);

}

void triangle()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//Triangle
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 255);
	glVertex2f(125,75+200); //left
	glVertex2f(175, 125+200); //middle
	glVertex2f(225, 75+200); //right
	glEnd();

	//Rectangle
	glBegin(GL_POLYGON);
	glColor3f(255, 0, 0);

	glVertex2f(375, 375); //top left
	glVertex2f(300, 375); //top right
	glVertex2f(300, 300); //bottom left
	glVertex2f(375, 300); //bottom right
	glEnd();
	glFlush();
}



int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Triangle and Square");
	glutDisplayFunc(triangle);

	myInit();
	glutMainLoop();
	return 0;
}