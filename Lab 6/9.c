#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
int isCircular(struct Node *head) {
    if (head == NULL)
        return 0; 
    struct Node *temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;
    if (temp == head)
        return 1; 
    else
        return 0; 
}
void makeCircular(struct Node *head) {
    if (head == NULL)
        return;
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head; 
}
void display(struct Node *head) {
    struct Node *temp = head;
    printf("List elements: ");
    int count = 0;
    while (temp != NULL && count < 10) { 
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\n");
}
int main() {
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    display(head);
    if (isCircular(head))
        printf("The linked list is circular.\n");
    else
        printf("The linked list is NOT circular.\n");
    makeCircular(head);
    if (isCircular(head))
        printf("The linked list is now circular.\n");
    else
        printf("The linked list is NOT circular.\n");
    return 0;
}
