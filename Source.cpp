#include <GL\freeglut.h>
#include<math.h>
using namespace std;



#define PI 3.14 //calling pi value from math library
float //declaring angles for the Moons and giving values,used in draw() function
angleSecondMoon = 0.0,
angleFirstMoon = 60.0;

GLfloat x = 0.2, y = 0.2, z = 0.2; // used in scale for the planet in the middle
GLfloat Ambient[] = { 0.1,0.1,0.1,1.0 }; // used in initLighting() function to control the lighting for the moons
GLfloat Diffuse[] = { 1.0,1.0,1.0,1.0 };
GLfloat Specular[] = { 0.5,0.5,0.5,0.1 };
GLfloat Position[] = { 0.5,0.5,0.5,0.9 }; // used in draw function to set the position for the planet in the middle
GLfloat scale[3] = { 0.60 ,0.80 ,1.100 }; //used in orbit() function to scale the orbits
double angular1 = 2 * PI / 300; // = 0.021
double angular2 = 2 * PI / 50; // = 0.126


void initLighting() {

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); //create light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, Ambient); //background light that is scattered by the environment
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Diffuse); //surface receives light source and reflects equally in all directions
	glLightfv(GL_LIGHT0, GL_SPECULAR,Specular); //some of the reflected light is concentrated into a highlight or bright spot
}


void orbit() {

	glColor3f(0.5, 0.5, 0.5);

	int i = 0;

	for (i = 0; i < 3; i++) {
		glPushMatrix();
		glRotatef(63, 1.0, 0.0, 0.0);
		glScalef(scale[i], scale[i], scale[i]);
		glBegin(GL_POINTS);
		double angular3 = 0.0;
		int i = 0;
		for (i = 0; i < 300; i++)
		{
			glVertex2d(cos(angular3), sin(angular3));
			angular3 += angular1;
		}
		glEnd();
		glPopMatrix();
	}
}

void draw(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	orbit();

	glLoadIdentity();
	glPushMatrix(); //���� ��� �� ������� ��� ������� 
    //���� ����� ������� ��� ����� ���� ������ �� ������ ������ ��� ������ ���� ������ ������� �����
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL); //	���� ����� ������ ������� ��� ����� ���� ������ 
	glPushMatrix(); //���� ����� �����
    glColor3f(1.0, 0.0, 0.0);
	glScalef(x, y, z);
	glLightfv(GL_LIGHT0, GL_POSITION, Position); // ������� ���� ����� ��� ����

	 //������ ������ ��� �� ���� 
	glColor3f(0.1, 0.0, 0.9);
	glutSolidSphere(2, 100, 100);
	glPopMatrix();
	glScalef(0.2, 0.2, 0.2);

	 // ������ ������ ������
	 // ���� ���� ���� ������ ������
	glPushMatrix();

	glTranslatef(4.0, 0.0, 0.0); //������ ������ ������
	glColor3f(0.9, 0.0, 0.1); //  ��� ������ ������ 
	glScalef(0.1, 0.1, 0.1); // ���
	glutSolidSphere(2, 20, 50);// ������ ������ ���
	glPopMatrix();


	glPushMatrix();
	glRotatef(angleFirstMoon, 0.0, 1.0, -0.5); //First Moon ����� ����� ���� ���� �� �����
	glTranslatef(-5.7, 0.0, 0.0);// ������� � ����� ����� ����� ��������
	glColor3f(0.9, 0.0, 0.1);// ���������� ��� �� �����
	glScalef(0.2, 0.2, 0.2);//���
	glutSolidSphere(3, 50, 50);// ����� ����� ���
	glPopMatrix();


	glPushMatrix();
	glRotatef(angleSecondMoon, 0.0, 1.0, -1.0); //Second Moon ������ ����� ���� ���� �� �����
	glTranslatef(-5.0, 0.0, 0.0);// ������� � ����� ������ ����� ��������
	glColor3f(0.6, 0.0, 0.1);// ����������� ��� �� �����
	glScalef(0.4, 0.4, 0.4);// ���
	glutSolidSphere(1, 50, 50);//������ ����� ��� 


	glPushMatrix();
	glRotatef(45, 1.0, 1.0, 0.0); // 2����� ����� ������ ����
     //	��� ������ ���� ��� ������ 
	glPointSize(2);
	glColor3f(6.0, 7.0, 6.0);//2 ����� ��� ������ ���
	glScalef(1.2, 2.2, 1.2);//������ ������
	
	glBegin(GL_POINTS); //���� ��� ������
	double angular4 = 0.0;
	for (int i = 0; i < 50; i++) // for ��� ��� ������ ����
	{
			glVertex2d(cos(angular4), sin(angular4));	//���� ��� ��� ������ ���� ���� ����� ��� ������ 
			angular4 += angular2;
	}

	glEnd();
	glPopMatrix();
	glPopMatrix();
	glFlush();
}



void update(int value) { //���� ��� ��� ������� ������� ��� ������
  
angleFirstMoon += 0.25; // ����� ������
angleSecondMoon += 0.1; // ������ ������

glutPostRedisplay();
glutTimerFunc(20, update, 0); // ���� ��� ����� ���� �������
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Two Moons Around A Planet");
	initLighting();

	glutDisplayFunc(draw); // ��� ��� ��� ��������
	glutTimerFunc(25, update, 0); // ���� ��� ����� ���� �������
	glutMainLoop();
	return 0;
}