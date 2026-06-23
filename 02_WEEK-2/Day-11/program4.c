#include <stdio.h>
//function for factorial
int fact(int n){
    int result=1;
    for(int i=1; i<=n; i++){
      result=result*i;  
    }
    return result;
}
int main () {
    int n;
    printf("enter n");
    scanf("%d",&n);
    int factorial=fact(n);
    printf("factorial is %d",factorial);
    return 0;
}