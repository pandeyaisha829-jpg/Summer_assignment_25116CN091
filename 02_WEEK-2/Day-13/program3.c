#include <stdio.h>
//largest and smallest element of an array
int main () {
    int n;
    printf("enter n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
    printf("element %d:",i+1);
    scanf("%d",&arr[i]);
    }
int largest=arr[0];
int smallest=arr[0];
for(int i=1; i<n; i++){
    if(arr[i]>largest){
        largest=arr[i];
    }
    else if(arr[i]<smallest){
        smallest=arr[i];
    }
}
 printf("the elements in the array are");
for(int i=0; i<n; i++){
    printf("%d",arr[i]);
}
printf("largest elements is %d",largest);
printf("smallest elements is %d",smallest);
return 0;
}