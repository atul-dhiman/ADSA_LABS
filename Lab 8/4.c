#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to perform selection sort using node swaps
void selectionSort(struct Node** headRef) {
    struct Node* start = *headRef;
    struct Node* prevStart = NULL;

    while (start != NULL && start->next != NULL) {
        struct Node* minNode = start;
        struct Node* prevMin = prevStart;

        struct Node* ptr = start->next;
        struct Node* prevPtr = start;

        // Find the minimum node in the unsorted list
        while (ptr != NULL) {
            if (ptr->data < minNode->data) {
                minNode = ptr;
                prevMin = prevPtr;
            }
            prevPtr = ptr;
            ptr = ptr->next;
        }

        // Swap nodes if a smaller one is found
        if (minNode != start) {
            // Adjust previous node links
            if (prevMin != NULL)
                prevMin->next = start;
            if (prevStart != NULL)
                prevStart->next = minNode;

            // Swap next pointers
            struct Node* temp = start->next;
            start->next = minNode->next;
            minNode->next = temp;

            // Update head if needed
            if (start == *headRef)
                *headRef = minNode;

            // Update pointers for next iteration
            struct Node* t = start;
            start = minNode;
            minNode = t;
        }

        prevStart = start;
        start = start->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&head, val);
    }

    printf("\nOriginal Linked List:\n");
    printList(head);

    selectionSort(&head);

    printf("\nSorted Linked List:\n");
    printList(head);

    return 0;
}
