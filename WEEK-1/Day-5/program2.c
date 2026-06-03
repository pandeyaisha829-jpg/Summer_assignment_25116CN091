#include <stdio.h>
int main () {
    //to check the number is strong or not
    int n,sum=0,remainder,i,fact,originalnum;
    printf("enter n");
    scanf("%d",&n);
    originalnum=n;
    while(n>0){
        remainder=n%10;
    fact=1;
    for(i=1; i<=remainder; i++){
        fact=fact*i;
    }
    sum=sum+fact;
    n=n/10;
    }
    if(originalnum=sum && originalnum>0){
        printf("%d is a strong number",originalnum);
    }
    else{
        printf("%d is not a strong number",originalnum);
    }
    return 0;
}

