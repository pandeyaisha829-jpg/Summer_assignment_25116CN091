#include <stdio.h>
//program to find row wise sum
int main() {
    int rows, cols;
    int matrix[100][100];

    printf("Enter the number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2) {
        return 1;
    }

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 1;
            }
        }
    }

    printf("\nRow-wise sum:\n");
    for (int i = 0; i < rows; i++) {
        int row_sum = 0;
        for (int j = 0; j < cols; j++) {
            row_sum += matrix[i][j];
        }
        printf("Sum of Row %d = %d\n", i + 1, row_sum);
    }

    return 0;
}
