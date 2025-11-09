#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = c;
}
char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return stack[top--];
}
char queue[MAX];
int front = 0, rear = -1, count = 0;
void enqueue(char c) {
    if (count == MAX) {
        printf("Queue Overflow!\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = c;
    count++;
}
char dequeue() {
    if (count == 0) {
        printf("Queue Underflow!\n");
        return '\0';
    }
    char c = queue[front];
    front = (front + 1) % MAX;
    count--;
    return c;
}
int isPalindrome(char str[]) {
    int len = strlen(str);
    top = -1;
    front = 0;
    rear = -1;
    count = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) {  
            char ch = tolower(str[i]);
            push(ch);
            enqueue(ch);
        }
    }
    while (count > 0) {
        if (pop() != dequeue())
            return 0; 
    }
    return 1; 
}
int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';  
    if (isPalindrome(str))
        printf("The string is a palindrome.\n");
    else
        printf("The string is NOT a palindrome.\n");
    return 0;
}
