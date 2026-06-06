#include <stdio.h>
//function for perfect number
int is_perfect(int n){
int i,sum=0;
    for(i=1; i<=n/2; i++){
        if(n%i==0){
            sum=sum+i;
        }
    }
    if(sum==n && n>0){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int n;
    printf("enter n");
    scanf("%d",&n);
   if(is_perfect(n)){
    printf("%d is perfect ",n);
   } 
   else{
    printf("%d is not perfect",n);
   }
   return 0;
}