#include<string.h>
#include<stdio.h>
#include<stdlib.h>

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

error * newError(const char * text, int index, int line) {
    error * newError = malloc(sizeof(error));
    newError->index = index;
    newError->content = strdup(text);
    newError->line = line;
    return newError;
}

errorsList * newErrorsList() {
    errorsList * newErrList = malloc(sizeof(errorsList));
    newErrList->cap = 5;
    newErrList->len = 0;
    newErrList->errors = malloc(sizeof(error) * newErrList->cap);
    return newErrList;
}

void copyError(error * dst, const error * src) {
    dst->content = strdup(src->content);
    dst->index = src->index;
    dst->line = src->line;
}

void freeErrors(errorsList *errList) {
    for (int i = 0; i < errList->len; i++) {
        free(errList->errors[i].content);
    }
    free(errList->errors);
    free(errList);
}

void freeError(error * err) {
    free(err->content);
    free(err);
}

errorsList * evacuateErrList(errorsList* oldErrors) {
    errorsList * evacuatedErrors = newErrorsList();
    evacuatedErrors->cap = oldErrors->cap*2;
    evacuatedErrors->len = oldErrors->len;
    for (int i = 0; i < oldErrors->len; i++) {
        copyError(&(evacuatedErrors->errors[i]), &(oldErrors->errors[i]));
    }
    freeErrors(oldErrors);
    return evacuatedErrors;
}

errorsList * addError(errorsList * errList, const char * text, int index, int line) {
    error * newErr = newError(text, index, line);
    if(errList->cap == errList->len) {
        errorsList * newErrList = evacuateErrList(errList);
        copyError(&(newErrList->errors[newErrList->len++]), newErr);
        return newErrList;
    }
    copyError(&errList->errors[errList->len], newErr);
    errList->len++;
    freeError(newErr);
    return errList;
}

int isErrors(errorsList * errList) {
    if(errList->len > 0) return 1;
    return 0;
}

void printErrors(errorsList * errList) {
    for(int i = 0; i < errList->len; i++) {
        printf("Error occured: LINE #%d, INDEX %d --- %s\n", errList->errors[i].line, errList->errors[i].index, errList->errors[i].content);
    }
}