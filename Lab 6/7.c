#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        head->next = head; 
    } else {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}
void insertAfter(int target, int value) {
    if (head == NULL) {
        printf("List is empty. Cannot insert after %d.\n", target);
        return;
    }
    struct Node *temp = head;
    do {
        if (temp->data == target) {
            struct Node *newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
            printf("%d inserted after %d.\n", value, target);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Node with value %d not found in the list.\n", target);
}
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    display();
    insertAfter(20, 25);
    display();
    insertAfter(40, 50);
    display();
    insertAfter(100, 60); 
    display();
    return 0;
}
