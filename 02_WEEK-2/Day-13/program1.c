#include <stdio.h>
//input and display array
int main() {
int n;
printf("enter the number of elements");
scanf("%d",&n);
int arr[n];
printf("enter %d elements;\n",n);
for(int i=0; i<n; i++){
    printf("element %d:",i+1);
    scanf("%d",&arr[i]);
}
printf("the elements in the array are");
for(int i=0; i<n; i++){
    printf("%d",arr[i]);
}
printf("\n");
return 0;
}
