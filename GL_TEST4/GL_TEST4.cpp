#include "stdafx.h"
#include <gl/glut.h>
 

 

void display()
{
glClear(GL_COLOR_BUFFER_BIT); /*������� �������� ������*/ 
glBegin(GL_LINES);//������ ��������� ����� 
  glColor3f(0.0, 1.0, 0.0); //���� ������� 
  //������
  glVertex2f (0.1, 0.1);
  glVertex2f (-0.08, -0.1);

  glVertex2f (-0.08, -0.1);
  glVertex2f (0.26, -0.1);

  glVertex2f (0.26, -0.1);
  glVertex2f (0.1, 0.1);
  //������
  glVertex2f (-0.08, -0.1);
  glVertex2f (-0.26, -0.3);
  
  glVertex2f (-0.26, -0.3);
  glVertex2f (0.1, -0.3);
  
  glVertex2f (0.1, -0.3);
  glVertex2f (-0.08, -0.1);
  //� ��� ������
  glVertex2f (0.26, -0.1);
  glVertex2f (0.42, -0.3);
  
 glVertex2f (0.42, -0.3);
  glVertex2f (0.1, -0.3);
  
  glVertex2f (0.1, -0.3);
  glVertex2f (0.26, -0.1);

  glEnd(); 
glFlush(); /*������������ ��, ��� �� �������*/ 
}
 

int main( int argc, char** argv )
{
	glutInit(&argc, argv); 
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
  glutInitWindowSize(600, 600); 
  glutInitWindowPosition(100, 10); 
  glutCreateWindow("First window!"); 
  glClearColor(0.0, 0.0, 0.0, 0.0); 
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity(); 
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 
  glutDisplayFunc(display); 
  glutMainLoop(); 
  return 0;
}