#include <stdio.h>
//print prime numbers upto n
int main () {
    int n,i,a,j;
    printf("enter n");
    scanf("%d",&n);
    for(i=2; i<=n; i++){
    a=1;
    for(j=2; j<=i/2; j++){
        if(i%j==0){
        a=0;
        break;
        }
    }
    if(a==1){
        printf("%d\n",i);
    }
    }
    return 0;
    
}