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
void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
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
void findLengthAndMiddle() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int length = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    int mid = (length / 2) + 1;
    temp = head;
    for (int i = 1; i < mid; i++) {
        temp = temp->next;
    }
    printf("Length of the list: %d\n", length);
    printf("Middle node value: %d\n", temp->data);
}
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    display();
    findLengthAndMiddle();
    insertAtEnd(60);
    display();
    findLengthAndMiddle();
    return 0;
}
