#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "../field/field.h"

#define WIDTH 20
#define HEIGHT 10

int count_neighbors(int field[HEIGHT][WIDTH], int x, int y, CellType type);
void save_results_to_file(int field[HEIGHT][WIDTH], int generation_count);