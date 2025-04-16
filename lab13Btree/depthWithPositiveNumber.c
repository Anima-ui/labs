#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include "validators.h"

int maxOfTwo(double a, double b){
    return a > b ? a : b;
}

int depthOfBST(Node* root){
    if (root == NULL){
        return 0;
    }

    int depthLeft = depthOfBST(root->left);
    int depthRight = depthOfBST(root->right);

    return 1 + maxOfTwo(depthLeft, depthRight);
}