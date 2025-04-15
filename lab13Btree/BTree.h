#pragma once

typedef struct Node{
    double data;
    struct Node* left;
    struct Node* right;
} Node;


typedef struct BTree{
    Node* root;
} BTree;

Node* createNode(double value);
Node* insert(Node* root, double value);
void freeTree(Node* root);
void printTree(Node* root, int space);