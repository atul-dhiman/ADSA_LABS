#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct Queue {
    int arr[MAX];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

// Check if queue is full
int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}

// Enqueue element
void enqueue(struct Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = data;
}

// Dequeue element
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return data;
}

// Peek front element
int peek(struct Queue* q) {
    if (isEmpty(q))
        return -1;
    return q->arr[q->front];
}

// Display queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

// Merge two sorted queues
void mergeQueues(struct Queue* q1, struct Queue* q2, struct Queue* result) {
    while (!isEmpty(q1) && !isEmpty(q2)) {
        if (peek(q1) < peek(q2))
            enqueue(result, dequeue(q1));
        else
            enqueue(result, dequeue(q2));
    }

    // Add remaining elements
    while (!isEmpty(q1))
        enqueue(result, dequeue(q1));

    while (!isEmpty(q2))
        enqueue(result, dequeue(q2));
}

int main() {
    struct Queue q1, q2, merged;
    initQueue(&q1);
    initQueue(&q2);
    initQueue(&merged);

    // Example sorted data
    enqueue(&q1, 1);
    enqueue(&q1, 3);
    enqueue(&q1, 5);
    enqueue(&q1, 7);

    enqueue(&q2, 2);
    enqueue(&q2, 4);
    enqueue(&q2, 6);
    enqueue(&q2, 8);

    printf("Queue 1: ");
    display(&q1);
    printf("Queue 2: ");
    display(&q2);

    mergeQueues(&q1, &q2, &merged);

    printf("Merged Sorted Queue: ");
    display(&merged);

    return 0;
}
