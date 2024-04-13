#include <GL/glut.h> 
#include <GL/GLU.h> 
#include <GL/GL.h> 

#define _WINDOW_WIDTH 300
#define _WINDOW_HEIGHT 300

int mode = 0; 

static void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);	
	glColor3f(0.5, 0.5, 0.5); 

	if (mode == 0)
	{
		glBegin(GL_POLYGON);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
		glEnd();		
	}
	else if (mode == 1)
	{
		glutSolidTeapot((GLfloat)0.6);
	}		

	glFlush();
	
}

static void MyKeyboard(unsigned char keyPressed, int x, int y)
{
	switch (keyPressed)
	{
	case 'a':
		mode += 1; 
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
}

static void MyReshape(int newWidth, int newHeight)
{
	glViewport(0, 0, newWidth, newHeight); 
	GLfloat widthFactor = (GLfloat)newWidth / (GLfloat)_WINDOW_WIDTH;
	GLfloat heightFactor = (GLfloat)newHeight / (GLfloat)_WINDOW_HEIGHT;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * widthFactor, 1.0 * widthFactor, -1.0 * heightFactor, 1.0 * heightFactor, -1.0, 1.0);
}

int main(int argc, char* argv[])
{
	glutInit_ATEXIT_HACK(&argc, argv);
	glutInitDisplayMode(GLUT_RGB); 
	glutInitWindowSize(_WINDOW_WIDTH, _WINDOW_HEIGHT);
	glutInitWindowPosition(100, 100); 
	glutCreateWindow_ATEXIT_HACK("OpenGL Drawing Example");
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	
	glutDisplayFunc(MyDisplay);  
	glutKeyboardFunc(MyKeyboard); 
	//glutReshapeFunc(MyReshape); 
	glutMainLoop();

	return 0;
}