#include <stdio.h>


int readLine(FILE *fp, char *line) {
    int i = 0;
    int c;

    while (1) {
        c = fgetc(fp);
        if (c == EOF || c == '\n') {
            break;
        }
        line[i++] = c;
    }
    line[i] = '\0';

    return (i == 0 && c == EOF) ? 0 : 1;
}

void writeLine(FILE *fp, float value) {
    fprintf(fp, "%f\n", value);
}