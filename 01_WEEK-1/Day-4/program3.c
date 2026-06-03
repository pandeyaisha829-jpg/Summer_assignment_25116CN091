#include <stdio.h>
//to check the number is armstrong
int main() {
    int n,i,s=0,r;
    printf("input the number");
    scanf("%d",&n);
    i=n;
    while(n>0){
        r=n%10;
        s=s+r*r*r;
        n=n/10;
    }
    if(s==i){
        printf("armstrong");
    }
    else{
        printf("NA");
    }
    return 0;
}