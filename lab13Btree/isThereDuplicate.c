#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include "validators.h"
#include <stdbool.h>

bool contains(double* array, int size, double value){
    for (int i = 0; i < size; i++){
        if (array[i] == value) return true;
    }
    return false;
    
}


int amountOfNodes(Node* root){
    int amountL = 0;
    int amountR = 0;

    if (root == NULL) return 0;

    amountL += amountOfNodes(root->left);
    amountR += amountOfNodes(root->right);

    return 1 + amountL + amountR;
}



bool isThereDublicate(Node* root, double* values, int* index){
    if (root == NULL) return false;

    if (contains(values, *index, root->data)) return true;

    values[(*index)++] = root->data;

    return isThereDublicate(root->left, values, index) || isThereDublicate(root->right, values, index);
}


bool hasDuplicates(Node* root){
    int maxSize = amountOfNodes(root);
    double* values = malloc(maxSize * sizeof(int));
    int index = 0;

    bool res = isThereDublicate(root, values, &index);
    free(values);
    return res;
}