#include <stdio.h>
//program to frequency of an element
int main () {
    int arr[100],n,i,searchelement,count=0;
    printf("enter the number of elements in the array");
    scanf("%d",&n);
    printf("enter %d integers:\n",n);
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the element to search: ");
    scanf("%d",&searchelement);
    for(i=0; i<n; i++){
        if(arr[i]==searchelement){
            count++;
        }
    }
    if(count>0){
        printf("element %d occurs %d time(s) in the array.\n",searchelement,count);
    } 
    else{
        printf("the element %d is not present in the array (frequency=0).\n",searchelement);
    }
    return 0;
}