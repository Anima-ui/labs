#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "field/field.h"
#include "utils/utils.h"


int main() {
    int field[HEIGHT][WIDTH];
    srand(time(NULL));

    random_fill(field, 30); // 30% заполнение

    int generation_count = 0;
    const int max_generations = 1000;

    while (1) {
        system("cls");
        print_field(field);
        update_field(field);
        generation_count++;
        Sleep(200); // 200 миллисекунд

        if (_kbhit()) { 
            break;
        }

        if (generation_count >= max_generations) {
            break;
        }

        save_results_to_file(field, generation_count);
    }

    return 0;
}
