#include <stdio.h>
//program to count set bits in a number
int countSetBits(int n) {
    int count = 0;
    while(n>0){
        count += (n & 1);
        n=n>>1;
}
return count;
}
int main () {
    int num=29;
    printf("number of set bits in %d is: %d\n",num,countSetBits(num));
    return 0;
}