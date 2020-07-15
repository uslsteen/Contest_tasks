//
// Created by anon on 15.07.2020.
//
#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <time.h>
#include <assert.h>

/*num of pixels for one square*/
enum Params_of_the_field
{
    NUM_FOR_W = 30,
    NUM_FOR_H = 20,
    SCALE = 25
};

enum DIRECTIONS
{
    UP = 0,
    LEFT = 1,
    DOWN = 2,
    RIGHT = 3
};

struct snake_t
{
    int point_x;
    int point_y;
};

enum SIZE_OF_SNAKE
{
    START_SIZE = 3,
    MAX_SIZE = 100
};



class Snake
{
    /*for variables*/
public:

    static struct snake_t* snk;
    static const int width = SCALE*NUM_FOR_W;
    static const int heigth = SCALE*NUM_FOR_H;
    static int dir;

//private:

    /*for func*/
public:
    Snake();
    ~Snake();

    static void Draw_Field();

    static void Display();

    static void Moving();

    static void Draw_Snake();

    static void Timer(int value);

    static void MyKeyboard(int key, int param_1, int param_2);

//private:

};


#endif //SNAKE_SNAKE_H
