#include <iostream>
#include <stdlib.h>
#include <glut.h>
#include "ImageLoad.h"

using namespace std;

float _angle = 0.0f;
int yAxis = 0.0f;
int xAxis = 0.0f;

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 'w': // to move up 
		_angle += 1.5f;
		yAxis = 0.0f;
		xAxis = 1.0f;
		break;
	case 's': //to move down
		_angle -= 1.5f;
		yAxis = 0.0f;
		xAxis = 1.0f;
		break;
	case 'a': //to move left
		_angle += 1.5;
		yAxis = 1.0f;
		xAxis = 0.0f;
		break;
	case 'd': // to move right
		_angle -= 1.5;
		yAxis = 1.0f;
		xAxis = 0.0f;
		break;
	case 27: //Escape key
		exit(0);
		break;
	}
}

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
		0,                            //0 for now (level of mipmapping)
		GL_RGB,                       //Format OpenGL uses for image
		image->width, image->height,  //Width and height
		0,                            //The border of the image
		GL_RGB, //GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
		//as unsigned numbers
		image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

GLuint _textureId[6]; //The id of the texture

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_LIGHTING);  // disable light to avoid shadow on cube when rotates
	//glEnable(GL_LIGHT0);
	//glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	Image* image = loadBMP("01.bmp");
	_textureId[0] = loadTexture(image);
	delete image;
	image = loadBMP("02.bmp");
	_textureId[1] = loadTexture(image);
	delete image;
	image = loadBMP("03.bmp");
	_textureId[2] = loadTexture(image);
	delete image;
	image = loadBMP("04.bmp");
	_textureId[3] = loadTexture(image);
	delete image;
	image = loadBMP("05.bmp");
	_textureId[4] = loadTexture(image);
	delete image;
	image = loadBMP("06.bmp");
	_textureId[5] = loadTexture(image);
	delete image;
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void cubicDraw(){

	glTranslatef(-0.2, 0.5, -0.5);  // make it center abit
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId[0]);

	glPushMatrix();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glRotatef(_angle, xAxis, yAxis, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);

	//front
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.2f, 0.5f, 0.0f); //front upper-right
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.2f, -1.8f, 0.0f); // front lower-right
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, -1.8f, 0.0f);  //front lower-left
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f, 0.5f, 0.0f);  //front upper-left

	glEnd();
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId[1]);

	//right
	glPushMatrix();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glRotatef(_angle, xAxis, yAxis, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.2f, 0.5f, 0.0f); //front upper-right or right upper-left
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.2f, -1.8f, 0.0f); // front lower-right or right lower-left
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1.2f, -1.8f, -1.9f); // right lower-right
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(1.2f, 0.5f, -1.9f);  // right upper right
	glEnd();
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId[2]);
	//back
	glPushMatrix();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glRotatef(_angle, xAxis, yAxis, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.2f, 0.5f, -1.9f);  // right upper right or back upper-left
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.2f, -1.8f, -1.9f); // right lower-right or back lower-left
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, -1.8f, -1.9f); //  back lower-right
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f, 0.5f, -1.9f); // back upper-right
	glEnd();
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId[3]);
	//left
	glPushMatrix();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glRotatef(_angle, xAxis, yAxis, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.0f, 0.5f, 0.0f);  //front upper-left or left upper-right
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, -1.8f, 0.0f);  //front lower-left or left lower-right
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, -1.8f, -1.9f); // back lower-right or left lower-left
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f, 0.5f, -1.9f); // back upper-right or left upper-left
	glEnd();
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId[4]);
	//top
	glPushMatrix();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glRotatef(_angle, xAxis, yAxis, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.2f, 0.5f, 0.0f); //front upper-right 
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.2f, 0.5f, -1.9f);  // right upper right
	glTexCoord2f(1.2f, 1.0f);
	glVertex3f(-1.0f, 0.5f, -1.9f); // back upper-right
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f, 0.5f, 0.0f);  //front upper-left or left upper-right
	glEnd();
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId[5]);
	//bottom
	glPushMatrix();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glRotatef(_angle, xAxis, yAxis, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.2f, -1.8f, 0.0f); // front lower-right or right lower-left
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.2f, -1.8f, -1.9f);  // right lower-right or back lower-left
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, -1.8f, -1.9f); //  back lower-right
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f, -1.8f, 0.0f);  // front lower-left
	glEnd();
	glPopMatrix();
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -6.0f);

	//GLfloat ambientLight[] = {0.2f, 0.2f, 0.2f, 1.0f};
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	//GLfloat directedLight[] = {0.7f, 0.7f, 0.7f, 1.0f};
	//GLfloat directedLightPos[] = {-10.0f, 15.0f, 20.0f, 0.0f};
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, directedLight);
	//glLightfv(GL_LIGHT0, GL_POSITION, directedLightPos);

	cubicDraw();

	glutSwapBuffers();
}

void update(int value) {
	if (_angle > 360) {
		_angle -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);

	glutCreateWindow("Textures Cube");
	initRendering();

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0); //add timer
	glutMainLoop();
	return 0;
}
