#include <stdio.h>
//program to recursive reverse of a number
int reverse_recursive_helper(int num, int reversed_num){
    if(num==0){
        return reversed_num;
    }
    int last_digit =num%10;
    return reverse_recursive_helper(num/10,reversed_num*10+last_digit);
}
int reverse_number(int num){
    if(num==0){
        return 0;
    }
    return reverse_recursive_helper(num, 0);
}
int main () {
    int number=987654;
    int result=reverse_number(number);
    printf("original number : %d\n",number);
    printf("reversed number : %d\n",result);
    return 0;
}