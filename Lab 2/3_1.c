#include <stdio.h>
#include <string.h>
int main() {
    char username[100];
    printf("Enter username: ");
    scanf("%s", username);  
    int start = 0;
    int end = strlen(username) - 1;
    char temp;
    while (start < end) {
        temp = username[start];
        username[start] = username[end];
        username[end] = temp;
        start++;
        end--;
    }
    printf("Reversed username (in-place): %s\n", username);
    return 0;
}
