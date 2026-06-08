#include <stdio.h>
//print  pyramid pattern
int main () {
    int row,i,j;
    printf("enter the number of rows");
    scanf("%d",&row);
    for(i=1; i<=row; i++){
        for(j=1; j<=i; j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}



