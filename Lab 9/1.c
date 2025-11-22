#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Queue {
    struct Node* arr[100];
    int front, rear;
};
void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}
int isEmpty(struct Queue* q) {
    return q->front == -1;
}
void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 99) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}
struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* buildTreeLevelOrder() {
    struct Queue q;
    initQueue(&q);
    int data;
    printf("Enter root value (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1) return NULL;
    struct Node* root = createNode(data);
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        struct Node* current = dequeue(&q);
        int leftData, rightData;
        printf("Enter LEFT child of %d (-1 for no node): ", current->data);
        scanf("%d", &leftData);
        if (leftData != -1) {
            current->left = createNode(leftData);
            enqueue(&q, current->left);
        }
        printf("Enter RIGHT child of %d (-1 for no node): ", current->data);
        scanf("%d", &rightData);
        if (rightData != -1) {
            current->right = createNode(rightData);
            enqueue(&q, current->right);
        }
    }
    return root;
}
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main() {
    struct Node* root = buildTreeLevelOrder();
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n");
    return 0;
}
