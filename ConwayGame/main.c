#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "field/field.h"
#include "utils/utils.h"


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
