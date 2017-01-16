#include <Windows.h>
#include <glut.h>
//function prototypes
void drawHead();
void drawNeck();
void drawLeftArm();
void drawBody();
void drawRightArm();
void drawLegs();

void initialization()
{
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0, 0, 0, 1);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	drawHead();
	drawNeck();
	drawBody();
	drawLeftArm();
	drawRightArm();
	drawLegs();
	glutSwapBuffers();

}
void drawHead()
{
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.15f, 0.95f);
	glVertex2f(-0.15f, 0.95f);
	glVertex2f(-0.15f, 0.65f);
	glVertex2f(0.15f, 0.65f);
	glEnd();

}
void drawNeck()
{
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.1f, 0.65f);
	glVertex2f(-0.1f, 0.6f);
	glVertex2f(0.1f, 0.6f);
	glVertex2f(0.1f, 0.65f);
	glEnd();
}
void drawBody()
{
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-0.25f, 0.6f);
	glVertex2f(-0.25f, -0.1f);
	glVertex2f(0.25f, -0.1f);
	glVertex2f(0.25f, 0.6f);
	glEnd();
	
	//Green Pocket
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.2f, 0.05f);
	glVertex2f(-0.2f, -0.05f);
	glVertex2f(-0.1f, -0.05f);
	glVertex2f(-0.1f, 0.05f);
	glEnd();
}
void drawLeftArm()
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.3f, 0.6f);
	glVertex2f(-0.3f, 0.3f);
	glVertex2f(-0.25f, 0.3f);
	glVertex2f(-0.25f, 0.6f);
	glEnd();
}
void drawRightArm()
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.25f, 0.6f);
	glVertex2f(0.25f, 0.55f);
	glVertex2f(0.55f, 0.55f);
	glVertex2f(0.55f, 0.6f);
	glEnd();
}
void drawLegs()
{
	//Left Leg
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.2f, -0.1f);
	glVertex2f(-0.2f, -0.6f);
	glVertex2f(-0.1f, -0.6f);
	glVertex2f(-0.1f, -0.1f);
	glEnd();

	//Right leg
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.2f, -0.1f);
	glVertex2f(0.2f, -0.6f);
	glVertex2f(0.1f, -0.6f);
	glVertex2f(0.1f, -0.1f);
	glEnd();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);

	glutCreateWindow("Cheah Pe Hao Test One");
	initialization();
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}