#include <stdio.h>
int check_palindrome(int n){
int original,reverse=0,remainder;
original=n;
while(n!=0){
    remainder=n%10;
    reverse=reverse*10+remainder;
    n=n/10;
}
if(original==reverse && original>=0){
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
    if(n<0){
        printf("%d is not a palindrome",n);
    }
    else if(check_palindrome(n)){
         printf("%d is a palindrome",n);
    }
    else{
         printf("%d is not a palindrome",n);
    }
    return 0;
}