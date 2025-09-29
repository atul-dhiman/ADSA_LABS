#include <stdio.h>
#include <string.h>
struct Book {
    char title[50];
    char author[50];
    float price;
};
int main() {
    int n, i;
    float priceLimit;
    printf("Enter number of books: ");
    scanf("%d", &n);
    struct Book books[n];
    for (i = 0; i < n; i++) {
        printf("\nBook %d details:\n", i + 1);
        printf("Enter title: ");
        scanf(" %[^\n]", books[i].title); 
        printf("Enter author: ");
        scanf(" %[^\n]", books[i].author);
        printf("Enter price: ");
        scanf("%f", &books[i].price);
    }
    printf("\nEnter price threshold: ");
    scanf("%f", &priceLimit);
    printf("\nBooks with price above %.2f:\n", priceLimit);
    for (i = 0; i < n; i++) {
        if (books[i].price > priceLimit) {
            printf("Title: %s, Author: %s, Price: %.2f\n",
                   books[i].title, books[i].author, books[i].price);
        }
    }
    return 0;
}
