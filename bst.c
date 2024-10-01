#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

Node_t* addNode(Node_t* newNode, int value, bool* successFlag) {
    if (!newNode) {
        newNode = (Node_t*)malloc(sizeof(Node_t));
        newNode->value = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
    } else {
        if (value == newNode->value) {
            *successFlag = false;
            printf("Sorry! The value cannot be the same!\n");
        } else if (value < newNode->value) {
            newNode->left = addNode(newNode->left, value, successFlag);
        } else if (value > newNode->value) {
            newNode->right = addNode(newNode->right, value, successFlag);
        }
    }
    return newNode;
}

void inTraversal(Node_t* binTree) {
    if (binTree) {
        inTraversal(binTree->left);
        printf("%d ", binTree->value);
        inTraversal(binTree->right);
    }
}

Node_t* deleteNode(Node_t* binTreeNode, int value, bool* successFlag) {
    if (binTreeNode == NULL) {
        *successFlag = false;
        printf("The tree doesn't exist!\n");
    } else if (value < binTreeNode->value) {
        if (binTreeNode->left == nullptr) {
            *successFlag = false;
            printf("Sorry! value: `%d` does NOT exist in the tree!\n", value);
        } else {
            binTreeNode->left = deleteNode(binTreeNode->left, value, successFlag);
        }
    } else if (value > binTreeNode->value) {
        if (binTreeNode->right == nullptr) {
            *successFlag = false;
            printf("Sorry! value: `%d` does NOT exist in the tree!\n", value);
        } else {
            binTreeNode->right = deleteNode(binTreeNode->right, value, successFlag);
        }
    } else {
        if (binTreeNode->left == nullptr && binTreeNode->right == nullptr) {
            free(binTreeNode);
            return nullptr;
        } else if (binTreeNode->left == nullptr) {
            Node_t* temp = binTreeNode;
            binTreeNode = binTreeNode->right;
            free(temp);
        } else if (binTreeNode->right == nullptr) {
            Node_t* temp = binTreeNode;
            binTreeNode = binTreeNode->left;
            free(temp);
        } else {
            Node_t* succeNode = FindRightMin(binTreeNode->right);
            binTreeNode->value = succeNode->value;
            binTreeNode->right = deleteNode(binTreeNode->right, succeNode->value, successFlag);
        }
    }
    return binTreeNode;
}

Node_t* FindRightMin(Node_t* binTreeNode) {
    Node_t* minNode = binTreeNode;
    while (minNode->left != nullptr) {
        minNode = minNode->left;
    }
    return minNode;
}

Node_t* findNode(Node_t* binTreeNode, int value) {
    if (binTreeNode == NULL) {
        printf("The tree doesn't exist!\n");
    } else if (value == binTreeNode->value) {
        printf("Found! Value: `%d` is in the tree!\n", value);
    } else if (value < binTreeNode->value) {
        if (binTreeNode->left == nullptr) {
            printf("Sorry! Value: `%d` does NOT exist in the tree!\n", value);
        } else {
            binTreeNode->left = findNode(binTreeNode->left, value);
        }
    } else if (value > binTreeNode->value) {
        if (binTreeNode->right == nullptr) {
            printf("Sorry! Value: `%d` does NOT exist in the tree!\n", value);
        } else {
            binTreeNode->right = findNode(binTreeNode->right, value);
        }
    }
    return binTreeNode;
}

int getSize(Node_t* binTreeNode) {
    if (binTreeNode == NULL) {
        return 0;
    } else {
        return getSize(binTreeNode->left) + 1 + getSize(binTreeNode->right);
    }
}

int kthSmallest(Node_t* binTreeNode, int k, int countNum) {
    int leftSize;
    if (binTreeNode == nullptr) {
        return NULL;
    }
    if (k < 1 || k > countNum) {
        return -1;
    }
    leftSize = getSize(binTreeNode->left);
    if (k <= leftSize) {
        return kthSmallest(binTreeNode->left, k, countNum);
    } else if (k == leftSize + 1) {
        return binTreeNode->value;
    } else {
        return kthSmallest(binTreeNode->right, k - (leftSize + 1), countNum);
    }
}
