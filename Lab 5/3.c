#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data, i;
    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return NULL;
    }
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head = createNode(data);
    temp = head;
    for (i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode = createNode(data);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("\nLinked List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    head = createList(n);
    displayList(head);
    return 0;
}
