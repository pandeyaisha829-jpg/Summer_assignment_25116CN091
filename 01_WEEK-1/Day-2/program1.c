#include <stdio.h>
//sum of digits of aa number
int main () {
    int n,i,s=0,remainder;
    printf("enter the value of n");
    scanf("%d",&n);
    while(n>0){
    remainder=n%10;
    s=s+remainder;
    n=n/10;
    }
    printf("sum of digits is %d",s);
}