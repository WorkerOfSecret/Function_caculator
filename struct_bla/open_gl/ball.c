#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <unistd.h>
#include <math.h>

#define pi 3.14159
#define g -9.806
#define time 100
#define white 1.0
#define initial 0.0
#define Max_h 480.0
#define Min_h -480.0

static float ang = 10.0;
double ballx = 0, bally = 0, ballz = 0;
double vx = 0, vy = 0;
double t = 1;
int angle = 0;

struct move
{
    double x, y;
    double v, vw;
    double r, m;
};

struct move ball = {initial, Min_h + 40, initial, initial, 40, 1};
double data[] = {initial, initial, initial};

void anime()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Screen
    glPushMatrix();
    glColor3f( white, white, white);
    glRectf( Min_h - 10, Min_h -10, Max_h + 10, Max_h + 10);
    glColor3f( initial, initial, initial );
    glRectf( Min_h, Min_h, Max_h, Max_h );
    glPopMatrix();
    
    // Ball
    glPushMatrix();
    glColor3f(white, white, initial);
    glTranslatef(ball.x, ball.y, 0);
    glutSolidSphere(ball.r, 45, 2);
    glPopMatrix();
    glutSwapBuffers();
}


void move()
{
    float e = 0.9;
    
    if (ball.y <= (Min_h + ball.r))
    {
        ball.y = Min_h+ball.r;
        ball.v = -(e * ball.v);
        t = 1;
    }
    else
    {
        ball.v = g * t;
    }
    
    data[0] = ball.x = vx*t;
    data[1] = ball.y = (ball.v*t) + (0.5) * (g*(t*t));
    
    
    printf ("t: %lf y: %lf vy: %lf\n", t, ball.y, ball.v);
    glutPostRedisplay();
}


void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
}


void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500.0, 500.0, -500.0, 500.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void mouse(int button, int state, int x, int y)
{
    switch (button) 
    {
        case GLUT_LEFT_BUTTON:
            if ( state == GLUT_DOWN)
                glutIdleFunc(move);
            break;
        case GLUT_RIGHT_BUTTON:
           if ( state == GLUT_DOWN)
               glutIdleFunc(NULL);
            break; 
        default:
            break; 
    }
}

void keyboard(unsigned char key, int x, int y)
{
    if ( key == '\x1b') exit(0);
    switch (key)
    {
        case 'a':
            ball.x -= 10;
            break;
        case'd':
            ball.x += 10;
            break;
        default:
            break;
    }
}


void timer(int value)
{
    t += time/1000;
    glutPostRedisplay();
    glutTimerFunc(time, timer, 0);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (Max_h, Max_h);
    glutInitWindowPosition(100,100);
    glutCreateWindow(argv[0]);
    init();
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutTimerFunc(time, timer, 0);
    glutDisplayFunc(anime);
    glutMainLoop();
    
    return 0;
}
