#include <stdio.h>
//counting no of digits
int main () {
    int n, count=0;
    printf("enter n:");
    scanf("%d",&n);
    if(n==0){
        count=1;
    }
    else
    {
        if(n<0){
            n=-n;
        }
        while(n!=0){
            n/=10;
            count++;
        }
    }
    printf("number of digits: %d\n",count);
    return 0;
}