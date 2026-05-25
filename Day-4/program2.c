#include <stdio.h>
//program to generate fibonacci series
int main () {
    int term1,term2,nextterm,n,i;
    term1=0,term2=1;
    printf("enter the value of n");
    scanf("%d",&n);
    if(n==1){
        printf("the first fibonacci term is %d",term1);
    }
    else if (n==2){
        printf("the second fibonacci term is %d",term2);
    }
    else{
    for(i=3; i<=n; i++){
        nextterm=term1+term2;
    term1=term2;
    term2=nextterm;
    }
    printf("the %d-th term of fibonacci series is %d",n,term2);
}
    return 0;
}