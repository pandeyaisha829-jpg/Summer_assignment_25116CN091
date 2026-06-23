#include <stdio.h>
//funtion for sum of two numbers
int add(int n1,int n2){
    return n1+n2;
}
int main () {
    int n1,n2;
    printf("enter n1 and n2");
    scanf("%d %d",&n1,&n2);
    int sum=add(n1,n2);
    printf("sum is %d",sum);
    return 0;
}