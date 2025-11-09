#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct Element {
    int data;
    int priority;
};
struct Element pq[MAX];
int size = 0;
int isFull() {
    return size == MAX;
}
int isEmpty() {
    return size == 0;
}
void enqueue(int data, int priority) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert (%d, %d)\n", data, priority);
        return;
    }
    pq[size].data = data;
    pq[size].priority = priority;
    size++;
    printf("Inserted element: Data = %d, Priority = %d\n", data, priority);
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return;
    }
    int highestPriorityIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i].priority > pq[highestPriorityIndex].priority)
            highestPriorityIndex = i;
    }
    printf("Dequeued element: Data = %d, Priority = %d\n",
           pq[highestPriorityIndex].data, pq[highestPriorityIndex].priority);

    for (int i = highestPriorityIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("\nPriority Queue elements (Data, Priority):\n");
    for (int i = 0; i < size; i++) {
        printf("(%d, %d) ", pq[i].data, pq[i].priority);
    }
    printf("\n");
}
int main() {
    int choice, data, priority;
    while (1) {
        printf("\n--- Priority Queue Operations ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Remove Highest Priority)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter priority: ");
            scanf("%d", &priority);
            enqueue(data, priority);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
