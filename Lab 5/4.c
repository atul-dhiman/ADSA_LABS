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
int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;          
        fast = fast->next->next;    
        if (slow == fast) {
            return 1; 
        }
    }
    return 0;  
}
void createLoop(struct Node* head, int position) {
    if (position == 0) return; 
    struct Node *temp = head, *loopNode = NULL;
    int count = 1;
    while (temp->next != NULL) {
        if (count == position)
            loopNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = loopNode;
}
int main() {
    struct Node* head = NULL;
    int n, data, loopPos;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }
    printf("Enter position to create loop (0 for no loop): ");
    scanf("%d", &loopPos);
    createLoop(head, loopPos);
    if (detectLoop(head))
        printf("\nLoop detected in the linked list!\n");
    else
        printf("\nNo loop found in the linked list.\n");
    return 0;
}
