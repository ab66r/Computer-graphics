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
	glPushMatrix(); //äÍÝÙ Ýíå ßá ÇáÑÓãÇÊ Çáí ÑÓãäÇåÇ 
    //äÝÚá ÎÇÕíÉ ÇáÊÃËíÑ Úáì ãÓÊæì ÇáÈË ÇáæÇÍÏ Ãæ ÇáÈßÓá ÇáæÇÍÏ Úáì ÇáÔÇÔå ÈÍíË äÓÊØíÚ ÇáÊÃËíÑ ÚáíåÇ
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL); //	äÝÚá ÎÇÕíÉ ÇáÊÛíÑ áÃááæÇä Úáì ãÓÊæì ÇáÈË ÇáæÇÍÏ 
	glPushMatrix(); //äÎÒä ÇáÔßá ÇáÃæá
    glColor3f(1.0, 0.0, 0.0);
	glScalef(x, y, z);
	glLightfv(GL_LIGHT0, GL_POSITION, Position); // ÇÅáÖÇÁÉ ãæÖÚ ÊÛííÑ Úáì íÚãá

	 //ÊÝÇÕíá ÇáßæßÈ Çáí Ýí ÇáäÕ 
	glColor3f(0.1, 0.0, 0.9);
	glutSolidSphere(2, 100, 100);
	glPopMatrix();
	glScalef(0.2, 0.2, 0.2);

	 // ÊÝÇÕíá ÇáßæßÈ ÇáÕÛíÑ
	 // äÍÝÙ ÝíåÇ ÑÓãÉ ÇáßæßÈ ÇáÕÛíÑ
	glPushMatrix();

	glTranslatef(4.0, 0.0, 0.0); //ÇáÕÛíÑ ÇáßæßÈ ÇäÊÞÇá
	glColor3f(0.9, 0.0, 0.1); //  áæä ÇáßæßÈ ÇáÕÛíÑ 
	glScalef(0.1, 0.1, 0.1); // ÍÌã
	glutSolidSphere(2, 20, 50);// ÇáÕÛíÑ ÇáßæßÈ ÑÓã
	glPopMatrix();


	glPushMatrix();
	glRotatef(angleFirstMoon, 0.0, 1.0, -0.5); //First Moon ÇÇáæá ÇáÞãÑ ÏæÑä ãÍæÑ Çæ ÇÊÌÇå
	glTranslatef(-5.7, 0.0, 0.0);// ÇÎÊÝÇÁå æ ÙåæÑå ÇÇáæá ÇáÞãÑ ÇäÊÞÇÇáÊ
	glColor3f(0.9, 0.0, 0.1);// ÇáÞãÑÇÇáæá áæä Ýí íÊÍßã
	glScalef(0.2, 0.2, 0.2);//ÍÌã
	glutSolidSphere(3, 50, 50);// ÇÇáæá ÇáÞãÑ ÑÓã
	glPopMatrix();


	glPushMatrix();
	glRotatef(angleSecondMoon, 0.0, 1.0, -1.0); //Second Moon ÇáËÇäí ÇáÞãÑ ÏæÑä ãÍæÑ Çæ ÇÊÌÇå
	glTranslatef(-5.0, 0.0, 0.0);// ÇÎÊÝÇÁå æ ÙåæÑå ÇáËÇäí ÇáÞãÑ ÇäÊÞÇÇáÊ
	glColor3f(0.6, 0.0, 0.1);// ÇáÞãÑÇáËÇäí áæä Ýí íÊÍßã
	glScalef(0.4, 0.4, 0.4);// ÍÌã
	glutSolidSphere(1, 50, 50);//ÇáËÇäí ÇáÞãÑ ÑÓã 


	glPushMatrix();
	glRotatef(45, 1.0, 1.0, 0.0); // 2ÇáÞãÑ Íæáíä ÇáãÍæÑ ãæÞÚ
     //	ÍÌã ÇáãÍæÑ íÚäí ÍÌã ÇáäÞÇØ 
	glPointSize(2);
	glColor3f(6.0, 7.0, 6.0);//2 ÇáÞãÑ Íæá ÇáãÍæÑ áæä
	glScalef(1.2, 2.2, 1.2);//ÇáÑÓãå ÇãÊÏÇÏ
	
	glBegin(GL_POINTS); //íÍÏÏ Ôßá ÇáãÍæÑ
	double angular4 = 0.0;
	for (int i = 0; i < 50; i++) // for ÍÈå ÍÈå ÇáäÞÇØ íÑÓã
	{
			glVertex2d(cos(angular4), sin(angular4));	//íÚãá Úáì ÌÚá ÇáäÞÇØ ÊáÊÝ ÈÔßá ÏÇÆÑí Íæá ÇáßæßÈ 
			angular4 += angular2;
	}

	glEnd();
	glPopMatrix();
	glPopMatrix();
	glFlush();
}



void update(int value) { //íÚãá Úáì ÌÚá ÇáÞãÑíä íÊÍÑßÇä Íæá ÇáßæßÈ
  
angleFirstMoon += 0.25; // ÇÃáæá ááßæßÈ
angleSecondMoon += 0.1; // ÇáËÇäí ááßæßÈ

glutPostRedisplay();
glutTimerFunc(20, update, 0); // íÚãá Úáì ÊÛííÑ ÓÑÚÉ ÇáÞãÑíä
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Two Moons Around A Planet");
	initLighting();

	glutDisplayFunc(draw); // åÐÇ Çáí Ýíå ÇáÑÓæãÇÊ
	glutTimerFunc(25, update, 0); // íÚãá Úáì ÊÛííÑ ÓÑÚÉ ÇáÞãÑíä
	glutMainLoop();
	return 0;
}