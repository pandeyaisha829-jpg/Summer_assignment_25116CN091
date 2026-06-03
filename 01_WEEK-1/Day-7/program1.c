#include <stdio.h>
//program to recursive factorial
long long factorial(int n);
int main() {
    int num;
    printf("enter a positive number");
    scanf("%d",&num);
    if(num<0){
        printf("factorial of a negative number does not exist");
    }
    else{
        printf("factorial of %d=%lld\n",num,factorial(num));
    }
    return 0;
}
long long factorial(int n){
    if(n<=1){
        return 1;
    }
    return n*factorial(n-1);
}