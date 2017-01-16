#include <Windows.h>
#include <glut.h>
#include <stdlib.h>
//Puan Nik, I realize actually no need to include so many things
//because glut.h includes everything we need to draw
//tapi might cannot run on other platform

//Since we already include <Windows.h>, it means this
//application only can run on Windows only
//Sincerely, Cheah Pe Hao 

using namespace std;
float angle = 30.0f;
float cameraAngle = 0.0f;
void initialization()
{
	glEnable(GL_DEPTH_TEST); //enable depth
	glEnable(GL_COLOR_MATERIAL); //enable colour
	glDepthFunc(GL_LESS); //Depth control
	glClearColor(0, 0, 0, 0);
}

void handleResize(int w, int h) //Handle resize
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);

}

void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear overlaps
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset to the drawing perspective
	
	glRotatef(cameraAngle, 0.0f, 1.0f, 0.0f); //Rotate the camera
	glTranslatef(0.0f, 0.0f, -5.0f); //Move forward 5 units
	glPushMatrix(); //Save the transformation so far

	glRotatef(angle, 0.0f, 1.0f, 0.0f); //Rotate about the y-axis
	
	//Drawing Pyramid
	glBegin(GL_TRIANGLES);
	
	glColor3f(1.0, 1.0,0.0); //Yellow
	glVertex3f(0.0, 0.9, 0.0); //top
	glVertex3f(-1.0, -0.1, 0.6); //left
	glVertex3f(0.0, -0.5, -0.6); //bottom
	
	glColor3f(1.0f, 1.0f, 1.0f); //White
	glVertex3f(0.0, 0.9, 0.0);
	glVertex3f(1.0, -0.1, 0.6);
	glVertex3f(0.0, -0.5, -0.6);
	
	glColor3f(0.0, 1.0f, 1.0f); //Cyan
	glVertex3f(0.0, 0.9, 0.0);
	glVertex3f(1.0, -0.1, 0.6);
	glVertex3f(0.0, 0.2, 1.3);

	glColor3f(1.0f, 0.0, 1.0f); //Purple
	glVertex3f(0.0, 0.9, 0.0);
	glVertex3f(-1.0, -0.1, 0.6);
	glVertex3f(0.0, 0.2, 1.3);
	
	glEnd();
	
	glPopMatrix();
	
	//draw base
	glPushMatrix();
	glRotatef(angle, 0.0, 1.0f, 0.0);
	glBegin(GL_QUADS);
	glColor3f(.0, .0, 1.0); //Color Blue
	glVertex3f(-1.0, -0.1, 0.6);
	glVertex3f(0.0, -0.5, -0.6);
	glVertex3f(1.0, -0.1, 0.6);
	glVertex3f(0.0, 0.2, 1.3);
	glEnd();
	glPopMatrix();

	glutSwapBuffers(); //Display the object
}

void update(int value) //Rotate the object
{
	angle += 1.0f;
	if (angle > 360)
	{
		angle -= 360;
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
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0); //Add a timer
	glutMainLoop();
	return 0;
}