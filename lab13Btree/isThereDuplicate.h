#pragma once
#include "BTree.h"
#include "validators.h"
#include <stdbool.h>


bool contains(double* array, int size, double value);
int amountOfNodes(Node* root);
bool isThereDublicate(Node* root, double* values, int* index);
bool hasDuplicates(Node* root);