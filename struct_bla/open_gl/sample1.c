#include <GL/glut.h>
#include <math.h>
#define pi 3.14159265

void display(void)
{  
    double i;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    /*glVertex2d(-0.9, -0.9);
    glVertex2d(0.9, -0.9);
    glVertex2d(0.9, 0.9);
    glVertex2d(-0.9, 0.9); */
    for (i = 0; i <= 360; i++)
    {
        glVertex2d(0.1 * cos(i*pi/180), 0.1 * sin(i*pi/180));
    }
    glEnd();
    glFlush();
}

void init(void)
{
    glClearColor(126.5, 0.0, 255.0, 1.0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(400,400);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
