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

    if (value <= root->data){
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

Node* findMinRightSubtree(Node* root){
    while (root && root->left != NULL){
            root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, double value){
    if (root == NULL) {
        printf("Value %.2lf not found in the tree\n", value);
        return NULL;
    }

    if (value < root->data){
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL){
            free(root);
            printf("Value %.2f was deleted\n", value);
            return NULL;
        } else if (root->left == NULL){
            Node* temp = root->right;
            free(root);
            printf("Value %.2f was deleted\n", value);
            return temp;
        } else if (root->right == NULL){
            Node* temp = root->left;
            free(root);
            printf("Value %.2f was deleted\n", value);
            return temp;
        } else {
            Node* minRightTree = findMinRightSubtree(root->right);
            root->data = minRightTree->data;
            root->right = deleteNode(root->right, minRightTree->data);
        }
    }

    return root;
}

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