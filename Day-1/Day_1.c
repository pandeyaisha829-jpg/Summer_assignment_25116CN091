#include <stdio.h>
//sum of first n natural number.
int main () {
    int i,n,s=0,remainder;
    printf("enter n");
    scanf("%d",&n);
    for(i=1; i<=n; i++){
    s=s+i;
    }
    printf(" sum is %d",s);

    return 0;
}