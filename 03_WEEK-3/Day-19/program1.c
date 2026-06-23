#include <stdio.h>
//program for adding matrices
int main() {
    int r, c, i, j;
    int a[100][100], b[100][100], sum[100][100];
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter elements of 1st matrix:\n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            scanf("%d", &a[i][j]);
    printf("Enter elements of 2nd matrix:\n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            scanf("%d", &b[i][j]);
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            sum[i][j] = a[i][j] + b[i][j];
    printf("Sum: \n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            printf("%d%c", sum[i][j], (j == c - 1) ? '\n' : ' ');
    return 0;
}
