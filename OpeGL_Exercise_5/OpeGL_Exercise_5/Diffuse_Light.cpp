#include<Windows.h>
#include<glut.h>

void initialization()
{
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	/*
	Below is the coding for making diffuse light.
	Set the position of the light
	Then choose which light
	*/
	GLfloat light0_position[] = { 1, -0.75, -1, 0.0 }; // parameter is x-pos,y-pos,z-pos,w-pos
	GLfloat diffuse_parameter[] = { 0.0, 0.5, 0.0, 0.0 }; //RGBA
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_parameter);
	glEnable(GL_LIGHT0);
	
	//Works like ambient, but not like ambient 
	//
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutSolidSphere(0.5, 100, 100); //glutSolidSphere(radius,lines of longitude, lines of latitude)

	glutSwapBuffers();

}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL_Exercise_5");
	initialization();
	glutDisplayFunc(display);
	glutMainLoop();

}