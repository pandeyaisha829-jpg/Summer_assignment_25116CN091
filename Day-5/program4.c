#include <stdio.h>
//program to print largest prime factor
int main () {
        long long n,num,i;
        long long maxprime=-1;
        printf("enter n");
        scanf("%lld",&n);
        num=n;
        while(n%2==0);{
        maxprime=2;
        n=n/2;
        }
        for(i=3; i*i<=n; i=i+2){
            while(n%i==0){
            maxprime=i;
                n=n/i;
            }
        }
        if(n>2){
            maxprime=n;
        }
        if(num>1){
        printf("the largest prime factor of %lld is %lld\n",num,maxprime);
        }
        else{
            printf("%lld has no prime factors \n",num);
        }
        return 0;
    }


        
