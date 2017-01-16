#include <Windows.h>
#include <glut.h>
#include <stdlib.h>
float x = 1.0f, y = 1.0f,z=1.0f;
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
	glScalef(x,y,z); //scale

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
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:  x -= 0.01f; y -= 0.01f; count++; break;

	case 10: x = 1.0f; y = 1.0f;
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
	case 19: x += 0.01f; y +=0.01f; count++; break;

	default: x = 1.0f; y = 1.0f; count = 0; break;
	}
	glutPostRedisplay();
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