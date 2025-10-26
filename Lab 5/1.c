#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void append(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct Node* reverseIterative(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;  
        current->next = prev; 
        prev = current;        
        current = next;        
    }
    return prev;  
}
struct Node* reverseRecursive(struct Node* head) {
    // Base case: empty list or last node
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* rest = reverseRecursive(head->next);
    head->next->next = head;  
    head->next = NULL;        
    return rest;              
}
int main() {
    struct Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    printf("Original Linked List:\n");
    printList(head);
    head = reverseIterative(head);
    printf("\nReversed (Iterative):\n");
    printList(head);
    head = reverseRecursive(head);
    printf("\nReversed Again (Recursive):\n");
    printList(head);
    return 0;
}
