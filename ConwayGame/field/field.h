#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 10

typedef enum {
    EMPTY = 0,
    TYPE_A = 1,  // @
    TYPE_B = 2   // *
} CellType;

void print_field(int field[HEIGHT][WIDTH]);
void update_field(int field[HEIGHT][WIDTH]);
void random_fill(int field[HEIGHT][WIDTH], int density);