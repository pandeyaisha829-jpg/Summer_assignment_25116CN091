#include <stdio.h>
//program for diagonal sum of matrix
int main() {
    int n;
    int matrix[100][100];
    int main_sum = 0;
    int secondary_sum = 0;

    printf("Enter the size of the square matrix: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        return 1;
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        main_sum += matrix[i][i];
        secondary_sum += matrix[i][n - 1 - i];
    }

    printf("Sum of main diagonal elements: %d\n", main_sum);
    printf("Sum of secondary diagonal elements: %d\n", secondary_sum);

    return 0;
}
