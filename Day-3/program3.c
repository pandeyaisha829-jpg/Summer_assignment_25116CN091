#include <stdio.h>
//gcd of two number
int main () {
    int n1,n2,i,gcd;
    printf("enter n1 and n2");
    scanf("%d%d",&n1,&n2);
    for(i=1; i<=n1 && i<=n2; i++){
        
            if(n1%i==0 && n2%i==0){
                gcd=i;
            }
            
        }
        printf("gcd is %d",gcd);
        return 0;

    
}