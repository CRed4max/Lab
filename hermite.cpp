#include <bits/stdc++.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

#define pi 3.142857
using namespace std;

struct Point {
    int x, y, z;

    Point() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    Point(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
        this->z = 0;
    }
};

Point p1, p2, t1, t2;

double h1(double t){
	return 2*pow(t, 3) - 3*pow(t, 2) + 1;
}
double h2(double t){
	return -2*pow(t, 3) + 3*pow(t, 2);
}
double h3(double t){
	return pow(t, 3)  - 2*pow(t, 2) + t;
}
double h4(double t){
	return pow(t, 3) - pow(t, 2);
}

void hermite_funcn(double t){
	double x = h1(t)*p1.x + h2(t)*t1.x + h3(t)*p2.x + h4(t)*t2.x;
	double y = h1(t)*p1.y + h2(t)*t1.y + h3(t)*p2.y + h4(t)*t2.y;
	glVertex2i((int)x, (int)y);
}


void hermite_curve() {
    for(double t=0; t<=1; t+=0.00001) {
        double x=0.0, y=0.0, z=0.0;
        hermite_funcn(t);
    }
}

void myInit (void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1200, 0, 780);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	
    hermite_curve();
	glEnd();
	glFlush();
}

int main (int argc, char** argv) {
	
	cin>>p1.x>> p1.y;
	cin>>p2.x>> p2.y;
	cin>>t1.x>> t1.y;
	cin>>t2.x>> t2.y;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Hermite Curve Drawing");
	myInit();

	glutDisplayFunc(display);
	glutMainLoop();
}
