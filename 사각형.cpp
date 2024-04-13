#include <GL/glut.h> 

static void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit_ATEXIT_HACK(&argc, argv);
	glutCreateWindow_ATEXIT_HACK("YES");
	glutDisplayFunc(MyDisplay);  
	glutMainLoop();

	return 0;
}