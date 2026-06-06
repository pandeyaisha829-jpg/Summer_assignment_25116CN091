#include <stdio.h>
//check the number is armstrong by using function
int check_armstrong(int n){
int s=0,r,i;
i=n;
while(n>0){
    r=n%10;
    s=s+r*r*r;
    n=n/10;
}
if(s==i){
    return 1;
}
else{
    return 0;
}
}
int main() {
    int n;
    printf("enter n");
    scanf("%d",&n);
 if(check_armstrong(n)){
         printf("%d is a armstrong",n);
    }
    else{
         printf("%d is not a armstrong",n);
    }
    return 0;
}