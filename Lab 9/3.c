#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int isBST(struct Node* root, int min, int max) {
    if (root == NULL)
        return 1;
    if (root->data <= min || root->data >= max)
        return 0;
    return isBST(root->left, min, root->data) &&
           isBST(root->right, root->data, max);
}
int isBinarySearchTree(struct Node* root) {
    return isBST(root, INT_MIN, INT_MAX);
}
int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->right = createNode(30);
    if (isBinarySearchTree(root))
        printf("The given tree is a BST\n");
    else
        printf("The given tree is NOT a BST\n");
    return 0;
}
