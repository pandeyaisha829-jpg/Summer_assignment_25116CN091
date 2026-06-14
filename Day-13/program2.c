#include <stdio.h>
int main () {
    int n,sum=0;
    float average;
    printf("enter n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
    printf("element %d:",i+1);
    scanf("%d",&arr[i]);
}
 for(int i=0; i<n; i++){
    sum=sum+arr[i];
 }
 average=(float)sum/n;

 printf("the elements in the array are");
for(int i=0; i<n; i++){
    printf("%d",arr[i]);
}
printf("sum of all elements is %d",sum);
printf("average of all elements is %f",average);
return 0;
}
