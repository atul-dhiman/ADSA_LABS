#include <stdio.h>
int main() {
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter numbers:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("\nChecking using bitwise AND:\n");
	for (int i = 0; i < n; i++) {
		if ((arr[i] & 1) == 0)
			printf("%d is Even\n", arr[i]);
		else
			printf("%d is Odd\n", arr[i]);
	}
	return 0;
}
