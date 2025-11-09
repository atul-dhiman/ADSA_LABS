#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtPosition(int value, int position) {
    struct Node *newNode = createNode(value);
    if (position <= 0) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        printf("%d inserted at position %d.\n", value, position);
        return;
    }
    struct Node *temp = head;
    int i;
    for (i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range! Node not inserted.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    printf("%d inserted at position %d.\n", value, position);
}
void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    insertAtPosition(10, 1); 
    insertAtPosition(20, 2); 
    insertAtPosition(15, 2);
    insertAtPosition(5, 1);
    insertAtPosition(50, 10);
    display();
    return 0;
}
