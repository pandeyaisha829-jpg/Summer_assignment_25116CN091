#include <stdio.h>
//print reverse  star pyramid  pattern
int main () {
    int row,i,j,k;
    printf("enter the number of rows");
    scanf("%d",&row);
    for(i=row; i>0; i--){
        for(j=0; j<row-i; j++){
            printf(" ");
        }
        for(k=0; k<(2*i-1); k++){
        printf("*");
    }
    printf("\n");
    }
    return 0;
}
