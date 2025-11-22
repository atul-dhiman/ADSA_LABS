#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data, height;
    struct Node *left, *right;
};
int max(int a, int b) { return (a > b) ? a : b; }
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
    printf("Rotation: RIGHT (LL case)\n");
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
struct Node* leftRotate(struct Node* x) {
    printf("Rotation: LEFT (RR case)\n");
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
struct Node* minValueNode(struct Node* root) {
    struct Node* temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
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
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    if (balance > 1 && data > node->left->data) {
        printf("Rotation: LEFT-RIGHT (LR case)\n");
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data) {
        printf("Rotation: RIGHT-LEFT (RL case)\n");
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = (root->left) ? root->left : root->right;
            if (temp == NULL) { 
                temp = root;
                root = NULL;
            } else {  
                *root = *temp;
            }
            free(temp);
        } 
        else { 
            struct Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    if (root == NULL)
        return root;
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        printf("Rotation: LEFT-RIGHT (LR case)\n");
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        printf("Rotation: RIGHT-LEFT (RL case)\n");
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main() {
    struct Node* root = NULL;
    int n, val, del;
    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("\nEnter value to delete: ");
    scanf("%d", &del);
    root = deleteNode(root, del);
    printf("\nHeight after deletion: %d\n", height(root));
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");
    return 0;
}
