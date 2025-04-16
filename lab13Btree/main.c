#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include "validators.h"
#include "isThereDuplicate.h"

int main(){
    Node* root = NULL;

    root = insert(root, 5.2);
    root = insert(root, 3.0);
    root = insert(root, 7.0);
    root = insert(root, 1.0);
    root = insert(root, 4.0);
    root = insert(root, 6.0);
    root = insert(root, 8.0);
    root = insert(root, 9.0);
    // root = insert(root, 7.0);

    printf("Tree:\n");
    printTree(root, 0);

    root = deleteNode(root, 1);
    root = deleteNode(root, 11);
    printTree(root, 0);

    if (hasDuplicates(root)){
        printf("There is a duplicate");
    } else {
        printf("There is no duplicates");
    }

    freeTree(root);
    return 0;
}