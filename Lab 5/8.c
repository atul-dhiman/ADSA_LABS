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
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void deleteFromBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;  
    printf("Deleted node with data %d from beginning.\n", temp->data);
    free(temp);
}
void deleteFromEnd(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node* temp = *head_ref;
    if (temp->next == NULL) {
        printf("Deleted node with data %d from end.\n", temp->data);
        free(temp);
        *head_ref = NULL;
        return;
    }
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted node with data %d from end.\n", temp->data);
    free(temp);
    prev->next = NULL;
}
void deleteFromPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head_ref;
    if (position == 1) {
        *head_ref = temp->next;
        printf("Deleted node with data %d from position %d.\n", temp->data, position);
        free(temp);
        return;
    }
    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    prev->next = temp->next;
    printf("Deleted node with data %d from position %d.\n", temp->data, position);
    free(temp);
}
int main() {
    struct Node* head = NULL;
    int choice, data, pos;
    int n;
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }
    while (1) {
        printf("\n--- Linked List Deletion Menu ---\n");
        printf("1. Delete from Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Delete from Given Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteFromBeginning(&head);
                break;
            case 2:
                deleteFromEnd(&head);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteFromPosition(&head, pos);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
