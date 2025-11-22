#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data, height;
    struct Node *left, *right;
};
int max(int a, int b) {
    return (a > b) ? a : b;
}
int height(struct Node* n) {
    if (n == NULL) return 0;
    return n->height;
}
int getBalance(struct Node* n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}
struct Node* rightRotate(struct Node* y) {
    printf("Rotation Performed: RIGHT ROTATION (LL Case)\n");
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
struct Node* leftRotate(struct Node* x) {
    printf("Rotation Performed: LEFT ROTATION (RR Case)\n");
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
struct Node* insert(struct Node* node, int data) {
    if (node == NULL)
        return createNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; 
    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);
    printf("Node %d → BF = %d\n", node->data, balance);
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    if (balance > 1 && data > node->left->data) {
        printf("Rotation Performed: LEFT-RIGHT (LR Case)\n");
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data) {
        printf("Rotation Performed: RIGHT-LEFT (RL Case)\n");
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main() {
    struct Node* root = NULL;
    int n, val;
    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nInsert value: ");
        scanf("%d", &val);
        root = insert(root, val);
        printf("-------------\n");
    }
    printf("\nFinal Inorder Traversal (AVL Tree): ");
    inorder(root);
    printf("\n");
    return 0;
}
