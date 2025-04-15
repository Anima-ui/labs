#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include "validators.h"

Node* createNode(double value){
    Node* node = malloc(sizeof(Node));
    node->left = node->right = NULL;
    node->data = value;
    return node;
}

Node* insert(Node* root, double value){
    if (root == NULL) return createNode(value);

    if (value < root->data){
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void freeTree(Node* root){
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Node* deleteNode(Node* root, double value){
//     if (root == NULL) {
//         printf("Value %.2lf not found in the tree.\n", value);
//         return NULL;
//     }


// }

void printTree(Node* root, int space) {
    if (root == NULL) return;

    int indent = 10;
    space += indent;

    printTree(root->right, space);

    printf("\n");
    for (int i = indent; i < space; i++) printf(" ");
    printf("%.2lf\n", root->data);

    printTree(root->left, space);
}