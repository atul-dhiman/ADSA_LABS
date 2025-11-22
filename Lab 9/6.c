#include <stdio.h>
#include <stdlib.h>
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
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
struct Node* kthSmallest(struct Node* root, int* k) {
    if (root == NULL)
        return NULL;
    struct Node* left = kthSmallest(root->left, k);
    if (left != NULL)
        return left;
    (*k)--;
    if (*k == 0)
        return root;
    return kthSmallest(root->right, k);
}
struct Node* kthLargest(struct Node* root, int* k) {
    if (root == NULL)
        return NULL;
    struct Node* right = kthLargest(root->right, k);
    if (right != NULL)
        return right;
    (*k)--;
    if (*k == 0)
        return root;
    return kthLargest(root->left, k);
}
int main() {
    struct Node* root = NULL;
    int n, value, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter the values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("Enter k: ");
    scanf("%d", &k);
    int k1 = k, k2 = k;
    struct Node* small = kthSmallest(root, &k1);
    struct Node* large = kthLargest(root, &k2);
    if (small)
        printf("K-th smallest = %d\n", small->data);
    else
        printf("Invalid k\n");
    if (large)
        printf("K-th largest = %d\n", large->data);
    else
        printf("Invalid k\n");
    return 0;
}
