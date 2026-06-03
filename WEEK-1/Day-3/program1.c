#include <stdio.h>
//check the number is prime
int main () {
    int n,i,a;
    printf("enter n");
    scanf("%d",&n);
    a=0;
    for(i=2; i<=n/2; i++){
        if(n%i==0){
        a=1;
        break;
        }
    }
    if(a==0){
        printf("prime");
    }
    else{
        printf("not prime");
    }
    
    return 0;
    
}