//Make a pentagon switch instantly from Red to Green to Blue. Color changes every second
#include <Windows.h>
#include <glut.h>

float colorRed=0, colorGreen=0, colorBlue=0;
int tick=1;
void initialization()
{
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(1.0f, 1.0f, 1.0f, 1);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glBegin(GL_POLYGON);
	glColor3f(colorRed, colorGreen, colorBlue);
	glVertex2f(0.0f, 0.75f); //Top 
	glVertex2f(-0.75f, 0.0f); //Left
	glVertex2f(-0.4f, -1.0f); //Btm left
	glVertex2f(0.4f, -1.0f); //Btm right
	glVertex2f(0.75f, 0.0f); //Right
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

void update(int value)
{
	switch (tick)
	{
	case 1: colorRed = 1.0f; colorGreen = 0.0f; colorBlue = 0.0f; tick = 2;
		break;
	case 2: colorRed = 0.0f; colorGreen = 1.0f; colorBlue = 0.0f; tick = 3;
		break;
	case 3: colorRed = 0.0f; colorGreen = 0.0f; colorBlue = 1.0f; tick = 1;
		break;
	}
	glutPostRedisplay(); //Display the latest change
	glutTimerFunc(1000, update, 0);

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 480);

	glutCreateWindow("Pentagon that switch Color");
	initialization();
	glutDisplayFunc(display);
	glutTimerFunc(1000, update, 0);
	glutMainLoop();
	return 0;
}