#include <stdio.h>
//funtion to find maximum
int max(int n1,int n2){
    if(n1>n2){
        return n1;
    }
    else{
            return n2;
        }
    }
int main () {
    int n1,n2;
    printf("enter n1 and n2");
    scanf("%d %d",&n1,&n2);
    int maximum=max(n1,n2);
    printf("the maximum number is %d",maximum);
    return 0;
    }

