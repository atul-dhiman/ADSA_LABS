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
        return;
    }
    struct Node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}
void display(struct Node *headRef) {
    if (headRef == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = headRef;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != headRef);
    printf("\n");
}
void splitCircularList(struct Node *head, struct Node **head1_ref, struct Node **head2_ref) {
    if (head == NULL)
        return;
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast->next->next == head)
        fast = fast->next;
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next = *head1_ref;
    fast->next = *head2_ref;
}
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);
    printf("Original Circular Linked List:\n");
    display(head);
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    splitCircularList(head, &head1, &head2);
    printf("\nFirst Half:\n");
    display(head1);
    printf("Second Half:\n");
    display(head2);
    return 0;
}
