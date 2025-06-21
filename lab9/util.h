#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

void printFileContentt(FILE* fp);

void fillFileWithNums(FILE* file);

double findAvgFromFile(FILE* fp);

void swapFirstLast(FILE* fp);