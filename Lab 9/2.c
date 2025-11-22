#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct QNode {
    struct Node* treeNode;
    struct QNode* next;
};
struct Queue {
    struct QNode* front;
    struct QNode* rear;
};
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(struct Queue* q, struct Node* node) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->treeNode = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;
    struct QNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    struct Node* node = temp->treeNode;
    free(temp);
    return node;
}
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* buildTree() {
    int data;
    printf("Enter root value (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1) return NULL;
    struct Node* root = createNode(data);
    struct Queue* q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        struct Node* current = dequeue(q);
        int leftData, rightData;
        printf("Enter left child of %d (-1 for no node): ", current->data);
        scanf("%d", &leftData);
        if (leftData != -1) {
            current->left = createNode(leftData);
            enqueue(q, current->left);
        }
        printf("Enter right child of %d (-1 for no node): ", current->data);
        scanf("%d", &rightData);
        if (rightData != -1) {
            current->right = createNode(rightData);
            enqueue(q, current->right);
        }
    }
    return root;
}
int height(struct Node* root) {
    if (root == NULL)
        return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}
int countLeaves(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}
int main() {
    struct Node* root = buildTree();
    printf("\n\nHeight of Tree: %d", height(root));
    printf("\nTotal Leaf Nodes: %d\n", countLeaves(root));
    return 0;
}
