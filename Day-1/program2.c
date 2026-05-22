#include <stdio.h>
//multiplication table of a given number
int main () {
    int i,n,result;
    printf("enter n");
    scanf("%d",&n);
    for(i=1; i<=10; i++){
        result=n*i;

    printf(" multiplication table is %d",result);
    }
    return 0;
}