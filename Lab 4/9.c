#include <stdio.h>
#include <stdlib.h>
struct IntMatrix {
    int rows;
    int cols;
    int **data; 
};
int main() {
    struct IntMatrix m;
    int i, j;
    printf("Enter number of rows: ");
    scanf("%d", &m.rows);
    printf("Enter number of columns: ");
    scanf("%d", &m.cols);
    m.data = (int **)malloc(m.rows * sizeof(int *));
    if (m.data == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (i = 0; i < m.rows; i++) {
        m.data[i] = (int *)malloc(m.cols * sizeof(int));
        if (m.data[i] == NULL) {
            printf("Memory allocation failed for row %d\n", i);
            return 1;
        }
    }
    printf("\nEnter elements for the %dx%d matrix:\n", m.rows, m.cols);
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &m.data[i][j]);
        }
    }
    printf("\nMatrix:\n");
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < m.rows; i++) {
        free(m.data[i]);
    }
    free(m.data);
    return 0;
}
