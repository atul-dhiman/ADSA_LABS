#include <stdio.h>
#include <stdlib.h>
struct Node {
    char data;
    struct Node* next;
};
struct Node* createNode(char c) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = NULL;
    return newNode;
}
void push(struct Node** top, char c) {
    struct Node* newNode = createNode(c);
    newNode->next = *top;
    *top = newNode;
}
int isEmpty(struct Node* top) {
    return top == NULL;
}
char pop(struct Node** top) {
    if (isEmpty(*top)) {
        return '\0';
    }
    struct Node* temp = *top;
    char popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
int isBalanced(char* expr) {
    struct Node* stack = NULL;
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(stack))
                return 0; 
            char topChar = pop(&stack);
            if (!isMatchingPair(topChar, ch))
                return 0; 
        }
    }
    return isEmpty(stack);
}
int main() {
    char expr[100];
    printf("Enter an expression: ");
    scanf("%s", expr);
    if (isBalanced(expr))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
