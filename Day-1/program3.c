#include <stdio.h>
//factorial of a given number
int main () {
    int i,n,factorial=1;
    printf("enter n");
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        factorial=factorial*i;

    printf(" factorial is %d",factorial);
    }
    return 0;
}