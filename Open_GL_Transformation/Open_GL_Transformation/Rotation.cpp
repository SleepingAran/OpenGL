#include <Windows.h>
#include <glut.h>
#include <stdlib.h>

float angle = 30.0f;
void initialization()
{
	glEnable(GL_COLOR_MATERIAL); //enable colour
	glClearColor(0, 0, 0, 0);
}

void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(angle, 0.0, 0.0, 1.0); //rotation by z axis
	glBegin(GL_QUADS);
	glVertex2f(-0.75f, 0.75f);
	glVertex2f(-0.75f, -0.75f);
	glVertex2f(0.75f, -0.75f);
	glVertex2f(0.75f, 0.75f);
	glEnd();
	glutSwapBuffers();
}

void update(int value) //Rotate the object
{
	angle += 1.0f;
	if (angle > 360)
	{
		angle -= 360;
	}
	glutPostRedisplay(); //Refresh display
	//update per 250 milliseconds
	glutTimerFunc(250, update, 0);
}

int main(int argc, char** argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //Double, Colour, Depth
	glutInitWindowSize(640, 480); //The windows size

	//Create the window
	glutCreateWindow("3D Open GL");
	initialization();

	glutDisplayFunc(drawScene);

	glutTimerFunc(250, update, 0); //Add a timer
	glutMainLoop();
	return 0;
}