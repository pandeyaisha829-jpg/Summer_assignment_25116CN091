#include <stdio.h>
//product of digit of a number
int main () {
    long long product=1;
    int n,remainder;
    printf("enter the value of n");
    scanf("%d",&n);
    if(n==0){
        product=0;
    }
    else{
        if(n<0){
            n=-n;
        }
        while(n>0){
            remainder=n%10;
            product=product*remainder;
            n=n/10;
        }
    }
    printf("product of digit is %d",product);
    return 0;
}