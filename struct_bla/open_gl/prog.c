#include <unistd.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#define win_size 500
#define pi 3.14159265
#define rgb 1.0/255.0

double radius = 0.1;
GLdouble ballx = 0;
GLdouble bally = 0;
GLdouble ballz = 0;

void resize(int w, int h)
{
    glViewport(0,0,w,h);
    glLoadIdentity();
    glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
}

void draw_ball(void)
{ 
    glColor3f(rgb * 255,rgb* 255, rgb * 255);
    glTranslatef(ballx, bally, ballz);
    glutSolidSphere(radius, 360, 2);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(rgb * 255, rgb * 255, rgb * 255);
    /*
    glBegin(GL_TRIANGLES);
    for(int i = 0.0; i<=360.0; i+=30.0)
    {
        glVertex2d(cos(i*pi/180), sin(i*pi/180));
    }
    glEnd();
    */
    draw_ball();
    
    glFlush();
}

void init(void)
{
    glClearColor(0, 0, rgb * 51, 1);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(win_size, win_size);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    init();
    glutMainLoop();
    return 0;
}


