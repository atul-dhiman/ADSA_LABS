#include <stdio.h>
#include <string.h>
struct Player {
    char name[50];
    int runs;
    int wickets;
};
int main() {
    int n;
    printf("Enter number of players in the team: ");
    scanf("%d", &n);
    struct Player team[n]; 
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of player %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", team[i].name); 
        printf("Runs: ");
        scanf("%d", &team[i].runs);
        printf("Wickets: ");
        scanf("%d", &team[i].wickets);
    }
    int maxIndex = 0; 
    for (int i = 1; i < n; i++) {
        if (team[i].runs > team[maxIndex].runs) {
            maxIndex = i;
        }
    }
    printf("\nPlayer with highest runs:\n");
    printf("Name: %s\n", team[maxIndex].name);
    printf("Runs: %d\n", team[maxIndex].runs);
    printf("Wickets: %d\n", team[maxIndex].wickets);
    return 0;
}
