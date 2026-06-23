#include <stdio.h>
#include <stdbool.h>
//funtion for checking prime number
int check_prime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2; i<=n/2; i++){
        if(n%i==0){
            return false;
        }
    }
            return true;
        }
    int main() {
        int n;
        printf("enter n");
        scanf("%d",&n);
        if(check_prime(n)){
        printf("%d is a prime number", n);
        }
        else{
            printf("%d is not a prime number",n);
        }
        return 0;

    }
