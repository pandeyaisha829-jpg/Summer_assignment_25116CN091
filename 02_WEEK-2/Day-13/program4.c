#include <stdio.h>
//count even and odd elements
int main () {
    int n;
    int even_count=0;
    int odd_count=0;
    printf("enter n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
    printf("element %d:",i+1);
    scanf("%d",&arr[i]);
    }
int largest=arr[0];
int smallest=arr[0];
for(int i=0; i<n; i++){
    if(arr[i]%2==0){
        even_count++;
    }
    else{
        odd_count++;
    }
}
 printf("the elements in the array are: ");
for(int i=0; i<n; i++){
    printf("%d ",arr[i]);
}
printf("even  elements is %d\n", even_count);
printf("odd elements is %d\n", odd_count);
return 0;
}