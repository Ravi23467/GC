#include <GL/glut.h>

void myInit ()
{
	//making background black at first
	//4 arguments
	glClearColor(0.0, 0.0, 0.0, 0.0);
	
	//making picture color red (in RGB mode)
	glColor3f(1.0, 0.0, 0.0);
	
	//breadth of picture boundary is 1 pixel
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	//setting window dimension in x- and y- direction
	gluOrtho2D(-780, 780, -420, 420);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
		glVertex2i(100, 100);
		glVertex2i(50, 200);
		glVertex2i(150, 200);
	glEnd();
	
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex2i(100, 100);
		glVertex2i(200, 100);
		glVertex2i(200, 200);
		glVertex2i(100, 200);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// giving window size in x- and y- direction
	glutInitWindowSize(1080, 720);
	glutInitWindowPosition(0, 0);
	
	//giving name to window
	glutCreateWindow("Circle Drawing");
	myInit();
	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
