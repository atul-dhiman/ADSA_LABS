#include <stdio.h>
#include <string.h>
int main() {
    char id[50];
    printf("Enter ID number: ");
    scanf("%s", id);  
    int len = strlen(id);
    int isPalindrome = 1; 
    for (int i = 0; i < len / 2; i++) {
        if (id[i] != id[len - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome)
        printf("The ID %s is a palindrome (string check)\n", id);
    else
        printf("The ID %s is NOT a palindrome (string check)\n", id);
    return 0;
}
