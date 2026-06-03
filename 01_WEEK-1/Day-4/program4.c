#include <stdio.h>
#include <math.h>
//to generate armstrong no upto a given no
int main() {
    int n,i,temp,remainder,digits,sum;
    printf("input the number");
    scanf("%d",&n);
    printf("armstrong number up to %d are:\n",n);
    for(i=1; i<=n; i++){
        temp=i;
        digits=0;
        sum=0;
        while(temp!=0){
            digits++;
            temp/=10;
        }
        temp=i;
        while(temp!=0){
            remainder=temp%10;
            sum+=round(pow(remainder,digits));
            temp/=10;
        }
        if(sum==i){
            printf("%d",i);
        }
    }
    printf("\n");
    return 0;

        }
