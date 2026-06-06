#include <stdio.h>
//function for fibonacci
int fibonacci(int n){
    int term1,term2,nextterm;
    term1=0,term2=1;
    if(n==1){
        return term1;
    }
    if(n==2){
        return term2;
    }
    for(int i=3; i<=n; i++){
        nextterm=term1+term2;
        term1=term2;
        term2=nextterm;
    }
    return nextterm;
}
int main() {
    int n;
    printf("enter n");
    scanf("%d",&n);
    int fibonacciterm=fibonacci(n);
    printf("%d-th term of fibonacci term sequence is %d",n,fibonacciterm);
return 0;
}