#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

int main() {
    FILE* inpF;
    char inpFString[50];
    Node_t* binTree = nullptr;
    int num;
    int countNum = 0;
    int selecNum;
    int userInp;
    bool successFlag;
    int kthSmall;

    printf("Enter the txt file path >> ");
    fgets(inpFString, 50, stdin);
    inpFString[strlen(inpFString) - 1] = '\0';

    if ((inpF = fopen(inpFString, "r")) == NULL) {
        printf("Open file error!!\n");
        system("PAUSE");
        exit(1);
    }

    while (!feof(inpF)) {
        fscanf(inpF, "%d", &num);
        binTree = addNode(binTree, num, &successFlag);
        countNum++;
    }
    fclose(inpF);

    printf("Inorder traversal: \n");
    inTraversal(binTree);
    printf("\n\n");

    while (1) {
        successFlag = true;
        do {
            printf("-------------------------------------------------------\n");
            printf("Present Inorder Traversal: \n");
            inTraversal(binTree);
            printf("\n\n");
            printf("* Function Table *\n");
            printf("1. Add a new Key value\n");
            printf("2. Delete a Key value\n");
            printf("3. Find a Key value\n");
            printf("4. Find the nth smallest key value\n");
            printf("5. Output sorting results of Key values (from min to max)\n");
            printf("6. End the program\n");

            printf("Select a function you want to test (1~6)>> ");
            scanf("%d", &selecNum);
            printf("\n");
        } while (selecNum < 1 || selecNum > 6);

        if (selecNum == 6) {
            printf("Program end.\n");
            break;
        }

        switch (selecNum) {
            case 1:
                printf("\n1. Add a new Key value\n");
                printf("Please Add a new Key value >> ");
                scanf("%d", &userInp);
                binTree = addNode(binTree, userInp, &successFlag);
                if (successFlag) {
                    printf("Add node `%d` successfully!\n", userInp);
                }
                printf("Inorder traversal: \n");
                inTraversal(binTree);
                printf("\n");
                break;

            case 2:
                printf("\n2. Delete a Key value\n");
                printf("Enter a Key value you want to delete >> ");
                scanf("%d", &userInp);
                binTree = deleteNode(binTree, userInp, &successFlag);
                if (successFlag) {
                    printf("Delete Key `%d` successfully!\n", userInp);
                }
                printf("Inorder traversal: \n");
                inTraversal(binTree);
                printf("\n");
                break;

            case 3:
                printf("3. Find a Key value\n");
                printf("Enter a Key value you want to find >> ");
                scanf("%d", &userInp);
                findNode(binTree, userInp);
                printf("Inorder traversal: \n");
                inTraversal(binTree);
                break;

            case 4:
                printf("4. Find the nth smallest key value\n");
                printf("Enter the kth smallest Key you want to find >> ");
                scanf("%d", &userInp);
                kthSmall = kthSmallest(binTree, userInp, countNum);
                if (kthSmall == -1) {
                    printf("Sorry! `%dth` smallest number is NOT in the tree!\n", userInp);
                } else {
                    printf("kth smallest: %d, Key: %d\n", userInp, kthSmall);
                }
                printf("Inorder traversal: \n");
                inTraversal(binTree);
                break;

            case 5:
                printf("5. Output sorting results of Key values (from min to max)\n");
                printf("Results: \n");
                inTraversal(binTree);
                break;

            default:
                break;
        }
        printf("\n\n\n");
    }

    printf("\n");
    system("pause");
    return 0;
}
