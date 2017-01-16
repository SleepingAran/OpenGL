#include <Windows.h>
#include <glut.h>
#include <stdlib.h>

float x=0, y=0;
int count=0;
void initialization()
{
	glEnable(GL_COLOR_MATERIAL); //enable colour
	glDepthFunc(GL_LESS); //Depth control
	glClearColor(0, 0, 0, 0);
}
void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(x, y, 0.0f); //translation
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
	switch (count)
	{
	case 0: 
	case 1: 
	case 2:
	case 3:
	case 4: x += 0.01f; y = 0; count++; break;

	case 5:
	case 6:
	case 7:
	case 8:
	case 9: y += 0.01f; x = 0; count++; break;

	case 10:
	case 11:
	case 12:
	case 13:
	case 14: x -= 0.01f; y = 0; count++; break;

	case 15:
	case 16:
	case 17:
	case 18:
	case 19: y -= 0.01f; x = 0; count++; break;

	default: x = 0; y = 0; count = 0; break;
	}
	glutPostRedisplay(); //Refresh display
	//update per 25 milliseconds
	glutTimerFunc(25, update, 0);
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

	glutTimerFunc(25, update, 0); //Add a timer
	glutMainLoop();
	return 0;
}