#include <GL/glut.h> 
#include <GL/GLU.h> 
#include <GL/GL.h> 

#define _WINDOW_WIDTH	500
#define _WINDOW_HEIGHT	500

int mode = 0;

static void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);

	glutWireTeapot(0.5); 
	
	glBegin(GL_POLYGON);
	glEnd(); 


	glFlush();
}

static void MyKeyboard(unsigned char keyPressed, int x, int y)
{
	/*
	switch (keyPressed)
	{
	case 'a':
		mode = (mode + 1) % 2;
		break;
	case 'A':
		mode += 1;
		break;
	case 'Q':
		exit(0);
		break;
	case 'q':
		exit(0);
		break;
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay(); 
	*/
}

static void MyReshape(int newWidth, int newHeight)
{
	glViewport(0, 0, newWidth, newHeight);
	GLfloat widthFactor = (GLfloat)newWidth / (GLfloat)_WINDOW_WIDTH;
	GLfloat heightFactor = (GLfloat)newHeight / (GLfloat)_WINDOW_HEIGHT;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * widthFactor, 1.0 * widthFactor,
		-1.0 * heightFactor, 1.0 * heightFactor, -1.0, 1.0);
}

int main(int argc, char* argv[])
{
	glutInit_ATEXIT_HACK(&argc, argv);	
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(_WINDOW_WIDTH, _WINDOW_HEIGHT);
	glutInitWindowPosition(200, 200);
	glutCreateWindow_ATEXIT_HACK("OpenGL Drawing Example");
	
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	//glutKeyboardFunc(MyKeyboard);

	glutMainLoop();

	return 0;
}