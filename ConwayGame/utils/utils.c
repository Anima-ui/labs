#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "utils.h"
#include "../field/field.h"

int count_neighbors(int field[HEIGHT][WIDTH], int x, int y, CellType type) {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
                if (field[ny][nx] == type) {
                    count++;
                }
            }
        }
    }
    return count;
}


void save_results_to_file(int field[HEIGHT][WIDTH], int generation_count) {
    int count_a = 0;
    int count_b = 0;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (field[y][x] == TYPE_A) count_a++;
            else if (field[y][x] == TYPE_B) count_b++;
        }
    }

    FILE* f = fopen("result.txt", "w");
    if (f) {
        fprintf(f, "Generations: %d\n", generation_count);
        fprintf(f, "TYPE_A cells: %d\n", count_a);
        fprintf(f, "TYPE_B cells: %d\n", count_b);

        if (count_a > count_b)
            fprintf(f, "Winner: TYPE_A (@)\n");
        else if (count_b > count_a)
            fprintf(f, "Winner: TYPE_B (*)\n");
        else
            fprintf(f, "Result: Draw\n");

        fclose(f);
    }
}