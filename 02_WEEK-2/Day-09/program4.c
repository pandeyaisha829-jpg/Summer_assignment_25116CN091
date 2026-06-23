#include <stdio.h>
//print character pyramid
int main () {
    char row,i,j;
    printf("enter the number of rows");
    scanf("%d",&row);
    for(i=0; i<row; i++){
        for(j=0; j<=row-i-1; j++){
            printf(" ");
        }
        char ch='A';
        for(j=0; j<=i; j++){
            printf("%c", ch++);
        }
        ch-=2;
        for(j=0; j<i; j++){
            printf("%c", ch--);
        }
        printf("\n");
    }
    return 0;
}
