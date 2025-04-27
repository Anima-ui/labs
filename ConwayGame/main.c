#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 10

#define EMPTY 0
#define TYPE_A 1  // @
#define TYPE_B 2  // *

void print_field(int field[HEIGHT][WIDTH]) {
    // Верхняя рамка
    for (int x = 0; x < WIDTH + 2; x++) {
        printf("-");
    }
    printf("\n");

    // Поле с боковыми рамками
    for (int y = 0; y < HEIGHT; y++) {
        printf("|");  // Левая рамка
        for (int x = 0; x < WIDTH; x++) {
            if (field[y][x] == TYPE_A) {
                printf("@");
            } else if (field[y][x] == TYPE_B) {
                printf("*");
            } else {
                printf(" "); // Пустая клетка — пробел
            }
        }
        printf("|\n");  // Правая рамка
    }

    // Нижняя рамка
    for (int x = 0; x < WIDTH + 2; x++) {
        printf("-");
    }
    printf("\n");
}

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

void update_field(int field[HEIGHT][WIDTH]) {
    int new_field[HEIGHT][WIDTH] = {0};

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int a_neighbors = count_neighbors(field, x, y, TYPE_A);
            int b_neighbors = count_neighbors(field, x, y, TYPE_B);
            int total_neighbors = a_neighbors + b_neighbors;

            if (field[y][x] == EMPTY) {
                if (total_neighbors == 3) {
                    if (a_neighbors > b_neighbors) {
                        new_field[y][x] = TYPE_A;
                    } else if (b_neighbors > a_neighbors) {
                        new_field[y][x] = TYPE_B;
                    } else {
                        new_field[y][x] = (rand() % 2 == 0) ? TYPE_A : TYPE_B;
                    }
                }
            } else {
                if (total_neighbors == 2 || total_neighbors == 3) {
                    new_field[y][x] = field[y][x];
                } else {
                    new_field[y][x] = EMPTY;
                }
            }
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            field[y][x] = new_field[y][x];
        }
    }
}

void random_fill(int field[HEIGHT][WIDTH], int density) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int r = rand() % 100;
            if (r < density) {
                field[y][x] = (rand() % 2) ? TYPE_A : TYPE_B;
            } else {
                field[y][x] = EMPTY;
            }
        }
    }
}

int main() {
    int field[HEIGHT][WIDTH];
    srand(time(NULL));

    random_fill(field, 30); // 30% заполнение

    while (1) {
        system("cls");
        print_field(field);
        update_field(field);
        Sleep(200); // 200 миллисекунд
    }

    return 0;
}
