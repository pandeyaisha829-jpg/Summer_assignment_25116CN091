#include <stdio.h>
//program to find X^n without pow()
double powerIterative(double x,int n){
    double result = 1.0;
    long long abs_n=n;
    if(abs_n<0){
        abs_n=-abs_n;
    }
    for(long long i=0; i<abs_n; i++){
        result*=x;
    }
    if(n<0){
        return 1.0/result;
    }
    return result;
}
int main () {
    double x=2.0;
    int n=-3;
    printf("%.2f raised to the power %d is :%f\n",x,n,powerIterative(x,n));
    return 0;
}