#include "stdafx.h"
#include <gl\glut.h>
 
// ������������� ���������� ����� � 1.0
// ����������� - �����
float red=1.0f, blue=1.0f, green=1.0f;
 
// ���� ��������
float angle = 0.0f;
 
void changeSize(int w, int h) {
	// �������������� ������� �� ����
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	// ���������� ������� ��������
	glMatrixMode(GL_PROJECTION);
	// �������� �������
	glLoadIdentity();
	// ���������� ��������� ��������
	glViewport(0, 0, w, h);
	// ���������� ���������� �����������
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	// ��������� � ������� ��������
	glMatrixMode(GL_MODELVIEW);
}
 
void renderScene(void) {
 
	// �������� ����� ����� � �������.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// �������� �������������
	glLoadIdentity();
	// ���������� ������
	gluLookAt( 0.0f, 0.0f, 10.0f,
		       0.0f, 0.0f,  0.0f,
		       0.0f, 1.0f,  0.0f);
	//������� �� �������� ��������
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	// ���������� ���� ������
	glColor3f(red,green,blue);
	glBegin(GL_TRIANGLES);
		glVertex3f(-2.0f,-1.5f, 0.0f);
		glVertex3f( 0.0f, 2.0f, 0.0);
		glVertex3f( 2.0f,-1.5f, 0.0);
	glEnd();
 
	angle+=0.04f;
 
	glutSwapBuffers();
}
 
void processNormalKeys(unsigned char key, int x, int y) {
 
	if (key == 27)
		exit(0);
}
 
void processSpecialKeys(int key, int x, int y) {
 
	switch(key) {
		case GLUT_KEY_F1 :
				red = 1.0;
				green = 0.0;
				blue = 0.0; break;
		case GLUT_KEY_F2 :
				red = 0.0;
				green = 1.0;
				blue = 0.0; break;
		case GLUT_KEY_F3 :
				red = 0.0;
				green = 0.0;
				blue = 1.0; break;
	}
}
 
int main(int argc, char **argv) {
 
	// �������������
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("���� 4");
 
	// �����������
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
 
	// ���� ����� �������
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
 
	// �������� ����
	glutMainLoop();
 
	return 1;
}