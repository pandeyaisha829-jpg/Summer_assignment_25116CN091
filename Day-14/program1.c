#include <stdio.h>
//program for linear search
int main () {
    int arr[100],n,i,searchelement,found=0;
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
            printf("element %d found at index %d (position %d).\n",searchelement,i,i+1);
            found=1;
            break;
        }
    }
    if(!found){
        printf("element %d is not present in the array.\n",searchelement);
    }
    return 0;
}