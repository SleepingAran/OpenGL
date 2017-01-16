//Drawing Jalur Gemilang
#include<Windows.h>
#include<glut.h>
#include<math.h>
#include<cmath>
#define PI 3.14159

void initialization()
{
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0,0,0, 1);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Sripes Start
	/*
	Draw every single sripes of Jalur Gemilang 
	line by line
	*/
	glBegin(GL_QUADS); //1
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.75f, 0.75f);
	glVertex2f(0.0f, 0.75f);
	glVertex2f(0.0f, 0.70f);
	glVertex2f(0.75f, 0.70f);
	glEnd();

	glBegin(GL_QUADS); //2
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.75f, 0.70f);
	glVertex2f(0.0f, 0.70f);
	glVertex2f(0.0f, 0.65f);
	glVertex2f(0.75f, 0.65f);
	glEnd();

	glBegin(GL_QUADS); //3
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.75f, 0.65f);
	glVertex2f(0.0f, 0.65f);
	glVertex2f(0.0f, 0.60f);
	glVertex2f(0.75f, 0.60f);
	glEnd();

	glBegin(GL_QUADS); //4
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.75f, 0.60f);
	glVertex2f(0.0f, 0.60f);
	glVertex2f(0.0f, 0.55f);
	glVertex2f(0.75f, 0.55f);
	glEnd();

	glBegin(GL_QUADS); //5
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.75f, 0.55f);
	glVertex2f(0.0f, 0.55f);
	glVertex2f(0.0f, 0.50f);
	glVertex2f(0.75f, 0.50f);
	glEnd();

	glBegin(GL_QUADS); //6
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.75f, 0.50f);
	glVertex2f(0.0f, 0.50f);
	glVertex2f(0.0f, 0.45f);
	glVertex2f(0.75f, 0.45f);
	glEnd();

	glBegin(GL_QUADS); //7
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.75f, 0.45f);
	glVertex2f(0.0f, 0.45f);
	glVertex2f(0.0f, 0.40f);
	glVertex2f(0.75f, 0.40f);
	glEnd();

	glBegin(GL_QUADS); //8
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.75f, 0.40f);
	glVertex2f(0.0f, 0.40f);
	glVertex2f(0.0f, 0.35f);
	glVertex2f(0.75f, 0.35f);
	glEnd();

	glBegin(GL_QUADS); //9
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.75f, 0.35f);
	glVertex2f(-0.75f, 0.35f);
	glVertex2f(-0.75f, 0.30f);
	glVertex2f(0.75f, 0.30f);
	glEnd();

	glBegin(GL_QUADS); //10
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.75f, 0.30f);
	glVertex2f(-0.75f, 0.30f);
	glVertex2f(-0.75f, 0.25f);
	glVertex2f(0.75f, 0.25f);
	glEnd();

	glBegin(GL_QUADS); //11
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.75f, 0.25f);
	glVertex2f(-0.75f, 0.25f);
	glVertex2f(-0.75f, 0.20f);
	glVertex2f(0.75f, 0.20f);
	glEnd();

	glBegin(GL_QUADS); //12
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.75f, 0.20f);
	glVertex2f(-0.75f, 0.20f);
	glVertex2f(-0.75f, 0.15f);
	glVertex2f(0.75f, 0.15f);
	glEnd();

	glBegin(GL_QUADS); //13
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.75f, 0.15f);
	glVertex2f(-0.75f, 0.15f);
	glVertex2f(-0.75f, 0.10f);
	glVertex2f(0.75f, 0.10f);
	glEnd();

	glBegin(GL_QUADS); //14
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.75f, 0.10f);
	glVertex2f(-0.75f, 0.10f);
	glVertex2f(-0.75f, 0.05f);
	glVertex2f(0.75f, 0.05f);
	glEnd();
	//Sripes End
	
	//Blue Square
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 0.75f);
	glVertex2f(-0.75f, 0.75f);
	glVertex2f(-0.75f, 0.30f);
	glVertex2f(0.0f, 0.30f);
	glEnd();
	//Blue Square end

	//Cresent Moon
	/*
	Create two circle using triangle fan
	The smaller circle drawn on the larger circle
	To create a cresent moon feeling
	*/
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-0.55f, 0.55f); // center of circle
	for (int i = 0; i <= 100; i++) {
		glVertex2f(
			-0.55f + (0.15 * cos(i *  2* PI / 100)),
			0.55f + (0.15 * sin(i * 2* PI / 100))
			);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.45f, 0.55f); // center of circle
	for (int i = 0; i <= 100; i++) {
		glVertex2f(
			-0.45f + (0.18 * cos(i * 2 * PI / 100)),
			0.55f + (0.14 * sin(i * 2 * PI / 100))
			);
	}
	glEnd();
	//Cresent moon end

	//Fourteen Spike Star
	glBegin(GL_TRIANGLE_FAN); 
	int tick=0;
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-0.25f, 0.55f); //center of star
	for (int i = 0; i <= 360; i++)
	{
		/*
		Formula is glVertex2f(x,y)
		While x = x_position_of_center_of_star + cosine (Degree) * radius
		and   y = y_position_of_center_of_star + sine (Degree) * radius
		Basically draw a circle with handicap
		*/
		float DegInRad = i * (360.0/28) *(PI / 180);
		if (tick % 2 == 0)
			glVertex2f(-0.25f + cos(DegInRad)*0.17f, 0.55f + sin(DegInRad)*0.17f);
		else
			glVertex2f(-0.25f + cos(DegInRad)*0.15f / 2, 0.55f + sin(DegInRad)*0.15f / 2);
		tick++;
	}
	glEnd();
	//Fourteen spike star end
	glutSwapBuffers(); 
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,600);

	glutCreateWindow("Jalur Gemilang");
	initialization();
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}