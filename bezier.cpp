#include <bits/stdc++.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

#define pi 3.142857
using namespace std;
int n;

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

vector<Point> points;

int factorial(int n) {
    int ans = 1;
    for(int i=2; i<=n; i++) {
        ans *= i;
    }
    return ans;
}

bool comp(Point &a, Point &b) {
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

double bezier_function(int i, int n, double t) {
    double ans = factorial(n);
    ans /= factorial(n-i);
    ans /= factorial(i);
    ans *= pow(t, i);
    ans *= pow(1-t, n-i);
    return ans;
}

void bezier_curve(vector<Point> points) {
    int n = points.size();
    for(double t=0; t<=1; t+=0.000001) {
        double x=0.0, y=0.0, z=0.0;
        for(int i=0; i<n; i++) {
            double c = bezier_function(i, n-1, t);
            x += points[i].x*c;
            y += points[i].y*c;
            // z += points[i].z*c;
        }
        glVertex2i((int)x, (int)y);
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
    sort(points.begin(), points.end(), comp);
    for(int i=1; i<points.size(); i++) {
        vector<Point> p;
        p.push_back(points[i-1]);
        p.push_back(points[i]);
        bezier_curve(p);
    }
    bezier_curve(points);
	glEnd();
	glFlush();
}

int main (int argc, char** argv) {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(Point(x, y));
    }

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Bezier Curve Drawing");
	myInit();

	glutDisplayFunc(display);
	glutMainLoop();
}
