#include <stdio.h>
//program to generate fibonacci series
int main () {
    int term1,term2,nextterm,n,i;
    term1=0,term2=1;
    printf("enter the value of n");
    scanf("%d",&n);
    printf("fibonacci series is %d %d",term1,term2);
    for(i=3; i<=n; i++){
        nextterm=term1+term2;
        printf("%d",nextterm);
    term1=term2;
    term2=nextterm;
    }
    return 0;


}