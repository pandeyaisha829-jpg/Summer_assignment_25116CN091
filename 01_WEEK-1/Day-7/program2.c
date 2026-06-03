#include <stdio.h>
//program to recursive fibonacci
long long fibonacci(int n);
int main() {
    int term;
    printf("enter position of term");
    scanf("%d",&term);
    if(term<0){
        printf("fibonacci number does not exist");
    }
    else{
        printf("fibonacci number at position %d=%lld\n",term,fibonacci(term));
    }
    return 0;
}
long long fibonacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}