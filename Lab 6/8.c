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
    printf("%d inserted.\n", value);
}
void deleteByValue(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *current = head, *prev = NULL;
    if (head->next == head && head->data == value) {
        free(head);
        head = NULL;
        printf("Deleted node with value %d.\n", value);
        return;
    }
    if (head->data == value) {
        struct Node *last = head;
        while (last->next != head)
            last = last->next;
        last->next = head->next;
        struct Node *temp = head;
        head = head->next;
        free(temp);
        printf("Deleted node with value %d.\n", value);
        return;
    }
    do {
        prev = current;
        current = current->next;
        if (current->data == value) {
            prev->next = current->next;
            free(current);
            printf("Deleted node with value %d.\n", value);
            return;
        }
    } while (current != head);
    printf("Node with value %d not found.\n", value);
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
    insertAtEnd(50);
    display();
    deleteByValue(10);  
    display();
    deleteByValue(30);  
    display();
    deleteByValue(50);  
    display();
    deleteByValue(100); 
    display();
    return 0;
}
