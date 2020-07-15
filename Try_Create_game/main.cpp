#include "snake.h"

int main(int argc, char** argv)
{
    Snake snk;

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(NUM_FOR_W*SCALE, NUM_FOR_H*SCALE);

    glutCreateWindow("Snake");
    glClearColor(1.0, 0.0, 5.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, NUM_FOR_W*SCALE, 0, NUM_FOR_H*SCALE);

    glutDisplayFunc(snk.Display);
    glutSpecialFunc(snk.MyKeyboard);
    glutTimerFunc(50, snk.Timer, 0);

    glutMainLoop();

    return 0;
}




