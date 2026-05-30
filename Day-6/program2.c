#include <stdio.h>
int main () {
    long long binary;
    int decimal=0,base=1,remainder;
    printf("enter a binary number;");
    scanf("%lld",&binary);
    long long temp=binary;
    while(temp>0){
        remainder=temp%10;
        decimal=decimal+remainder*base;
        temp=temp/10;
        base=base*2;
    }
    printf("binary:%lld\n",binary);
    printf("decimal:%d\n",decimal);
    return 0;
}