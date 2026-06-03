#include <stdio.h>
//program to recursive sum of digits
int recursive_sum_of_digits(int n){
    if(n<10){
        return n;
    }
    return (n%10)+recursive_sum_of_digits(n/10);
}
int main () {
    int num=12345;
    int result=recursive_sum_of_digits(num);
    printf("the recursive sum of digits for %d is:%d\n",num,result);
    return 0;
}