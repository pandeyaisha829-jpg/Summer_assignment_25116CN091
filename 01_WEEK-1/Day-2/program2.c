#include <stdio.h>
//reverse of a number
int main () {
    int n,i,reverse=0,remainder;
    printf("enter the value of n");
    scanf("%d",&n);
    while(n>0){
    remainder=n%10;
    reverse=reverse*10+remainder;
    n=n/10;
    }
    printf("reverse is %d",reverse);
}