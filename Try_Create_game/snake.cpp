//
// Created by anon on 15.07.2020.
//
#include "snake.h"

Snake::Snake()
{
    Snake::snk = (struct snake_t*)calloc(MAX_SIZE, sizeof(struct snake_t));
    assert(snk);

    snk[0].point_x = 10;
    snk[0].point_y = 10;
}

Snake::~Snake()
{
    if (snk != NULL)
        free(snk);
}

void Snake::Draw_Field()
{
    int i = 0, j = 0;

    glColor3f(.0, 1.0, 5.0);
    glBegin(GL_LINES);

    for (i = 0; i < width; i+= SCALE)
    {
        glVertex2f(i,0);
        glVertex2f(i,heigth);
    }

    for (j = 0; j < heigth; j+=SCALE)
    {
        glVertex2f(0, j);
        glVertex2f(width, j);
    }

    glEnd();
}


void Snake::Display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    Draw_Field();
    Draw_Snake();

    glFlush();
}


void Snake::Timer(int value)
{
    Display();

    Moving();

    glutTimerFunc(50, Timer, 0);
}


void Snake::Moving()
{
    int i = 0;

    for (i = START_SIZE; i > 0; i--)
    {
        snk[i].point_x = snk[i-1].point_x;
        snk[i].point_y = snk[i-1].point_y;
    }

    switch(dir)
    {
        case UP: snk[0].point_y++;
            break;

        case LEFT: snk[0].point_x--;
            break;

        case DOWN: snk[0].point_y--;
            break;

        case RIGHT: snk[0].point_x++;
            break;

        default: printf("Error in the func moving!\n");
            abort();
    }
}

void Snake::Draw_Snake()
{
    int i = 0;

    glColor3f(0.0, 0.0, 1.0);

    for (i = 0; i < START_SIZE; i++)
    {
        glRectf(snk[i].point_x*SCALE, snk[i].point_y*SCALE, (snk[i].point_x++)*SCALE, (snk[i].point_y)*SCALE);
    }
}

void Snake::MyKeyboard(int key, int param_1, int param_2)
{
    switch(key)
    {
        case 100: dir = LEFT;
            break;

        case 101: dir = UP;
            break;

        case 102: dir = RIGHT;
            break;

        case 103: dir = DOWN;
            break;

        default: printf("Unrecognized command\n");
            abort();
    }
}
