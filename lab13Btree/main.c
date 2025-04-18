#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"
#include "validators.h"
#include "isThereDuplicate.h"

int main(){
    int task;
    Node* root = NULL;

    do{
        printf("Select task:\n");
        printf("1. Create binary tree\n");
        printf("2. Delete specific element\n");
        printf("3. Check if there are duplicates\n");
        printf("4. Print tree\n");
        printf("5. Exit programm\n");

        task = getValidatedIntInput("Enter a number (1-5): ");

        switch (task) {
            case 1:
                root = createTree();
                break;

            case 2:
                double value = getValidatedIntInput("Input the value of the element: ");
                root = deleteNode(root, value);
                printTree(root, 0);
                break;

            case 3:
                if (hasDuplicates(root)) printf("There are at least 2 duplicates\n");
                else printf("There are no duplicates\n");
                break;
            
            case 4:
                printTree(root, 0);
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid task number\n");
                break;
        } 
    } while (task != 5);
    return 0;
}