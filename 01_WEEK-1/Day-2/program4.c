include <stdio.h>
//check the number is palindrome or not
int main () {
    int n,remainder,original,reverse=0;
    printf("enter the value of n");
    scanf("%d",&n);
    original=n;
        while(n!=0){
            remainder=n%10;
            reverse=reverse*10+remainder;
            n=n/10;
        }
        if(original==reverse && original>=0){
            printf("the number is palindrome %d",original);
        }
        else{
            printf("the number is not palindrome %d",original);
        }
    return 0;
}