#ifndef ERRORS_H
#define ERRORS_H
typedef struct {
    int index;
    int line;
    char * content;
}error;

typedef struct {
    error * errors;
    int len;
    int cap;
}errorsList;
errorsList * newErrorsList();
void freeErrors(errorsList *errList);
errorsList * addError(errorsList * errList, const char * text, int index, int line);
int isErrors(errorsList * errList);
void printErrors(errorsList * errList);
#endif