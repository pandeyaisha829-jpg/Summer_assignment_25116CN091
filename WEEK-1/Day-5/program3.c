#include <stdio.h>
int main () {
    //program to print prime factors of a number
        int n,i;
        printf("enter n");
        scanf("%d",&n);
        while(n%2==0);{
        printf("%d" , 2);
        n=n/2;
        }
        for(i=3; i<=n; i=i+2){
            while(n%i==0){
                printf("%d" , i);
                n=n/i;
            }
        }
        if(n>2){
            printf("%d" , n);
        }
        printf("\n");
        return 0;
    }


        
