#include <stdio.h>
#include <stdlib.h>
int *stack;   
int top = -1; 
int size;     
void push(int item) {
    if (top == size - 1) {
        printf("Stack Overflow! Cannot push %d\n", item);
    } else {
        top++;
        stack[top] = item;
        printf("%d pushed to stack.\n", item);
    }
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top → bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
int main() {
    int choice, item;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    stack = (int *)malloc(size * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    while (1) {
        printf("\n----- Stack Operations -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                free(stack);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
