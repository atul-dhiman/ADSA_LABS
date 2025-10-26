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
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    struct Node* result = NULL;
    if (list1->data <= list2->data) {
        result = list1;
        result->next = mergeSortedLists(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeSortedLists(list1, list2->next);
    }
    return result;
}
int main() {
    struct Node *list1 = NULL, *list2 = NULL, *mergedList = NULL;
    int n1, n2, data;
    printf("Enter number of nodes in first sorted list: ");
    scanf("%d", &n1);
    for (int i = 1; i <= n1; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        append(&list1, data);
    }
    printf("\nEnter number of nodes in second sorted list: ");
    scanf("%d", &n2);
    for (int i = 1; i <= n2; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        append(&list2, data);
    }
    printf("\nFirst Sorted Linked List: ");
    displayList(list1);
    printf("Second Sorted Linked List: ");
    displayList(list2);
    mergedList = mergeSortedLists(list1, list2);
    printf("\nMerged Sorted Linked List: ");
    displayList(mergedList);
    return 0;
}
