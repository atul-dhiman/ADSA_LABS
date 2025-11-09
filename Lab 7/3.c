#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int top = -1;
char *stack;
void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);  
    int len = strlen(str);
    stack = (char *)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }
    printf("Reversed string: ");
    for (int i = 0; i < len; i++) {
        printf("%c", pop());
    }
    free(stack);
    return 0;
}
