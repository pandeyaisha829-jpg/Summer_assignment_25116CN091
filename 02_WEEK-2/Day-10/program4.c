#include <stdio.h>
//print hollow square pattern
int main () {
    int row,i,j;
    printf("enter the number of rows");
    scanf("%d",&row);
    for(i=row; i>=1; i--){
        for(j=1; j<=row; j++){
            if(i==1 || i==row || j==1 || j==row){
            printf("*");
        }
        else{
        printf(" ");
    }
}
printf("\n");
    }
    return 0;
}

