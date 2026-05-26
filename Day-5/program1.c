#include <stdio.h>
int main () {
    //to check the number is perfect or not
    int n,sum=0,i;
    printf("enter n");
    scanf("%d",&n);
    for(i=1; i<=n/2; i++){
        if(n%i==0){
            sum=sum+i;
        }
    }
    if(sum==n && n>0){
        printf("%d is a perfect number",n);
    }
    else{
        printf("%d is not a perfect number",n);
    }
    return 0;

}