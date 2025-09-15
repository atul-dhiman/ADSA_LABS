#include <stdio.h>
#include <string.h>
int main() {
    char username[100];
    printf("Enter username: ");
    scanf("%s", username);
    int len = strlen(username);
    char reversed[100];
    for (int i = 0; i < len; i++) {
        reversed[i] = username[len - i - 1];
    }
    reversed[len] = '\0'; 
    printf("Reversed username (new array): %s\n", reversed);
    return 0;
}
