#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "utils.h"

int count_neighbors(int field[HEIGHT][WIDTH], int x, int y, int type) {
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