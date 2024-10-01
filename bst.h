#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node_t;

// 函數宣告
Node_t* addNode(Node_t* newNode, int value, bool* successFlag);  
Node_t* deleteNode(Node_t* binTreeNode, int value, bool* successFlag); 
Node_t* FindRightMin(Node_t* binTreeNode);
Node_t* findNode(Node_t* binTreeNode, int value);    
int kthSmallest(Node_t* binTreeNode, int k, int countNum);
int getSize(Node_t* binTreeNode);
void inTraversal(Node_t* binTree);

#endif
