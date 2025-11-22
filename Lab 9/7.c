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
struct Node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    struct Node* root = createNode(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}
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
    q->arr[++(q->rear)] = node;
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
void levelOrder(struct Node* root) {
    if (root == NULL)
        return;
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        struct Node* current = dequeue(&q);
        printf("%d ", current->data);
        if (current->left) enqueue(&q, current->left);
        if (current->right) enqueue(&q, current->right);
    }
}
int main() {
    int n;
    printf("Enter number of elements in sorted array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter sorted array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct Node* root = sortedArrayToBST(arr, 0, n - 1);
    printf("Level Order Traversal of Balanced BST:\n");
    levelOrder(root);
    return 0;
}
