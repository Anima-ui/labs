#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 10

#define EMPTY 0
#define TYPE_A 1  // @
#define TYPE_B 2  // *

void print_field(int field[HEIGHT][WIDTH]);
void update_field(int field[HEIGHT][WIDTH]);
void random_fill(int field[HEIGHT][WIDTH], int density);