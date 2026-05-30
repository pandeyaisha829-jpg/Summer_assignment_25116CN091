#include <stdio.h>
//decimal to binary conversion
void decimalTobinary(int n) {
int binarynum[32];
int i=0;
if (n==0) {
    printf("binary: 0\n");
    return;
}
while(n>0){
    binarynum[i]=n%2;
    n=n/2;
    i++;
}
printf("binary");
for(int j=i-1; j>=0; j--){
   printf("%d",binarynum[j]);
}
printf("\n");
}
int main () {
    int decimalnum;
    printf("enter a decimal number");
    scanf("%d",&decimalnum);
    decimalTobinary(decimalnum);
    return 0;
}