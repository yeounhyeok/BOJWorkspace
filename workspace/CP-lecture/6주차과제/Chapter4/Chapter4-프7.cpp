#include <stdio.h>

int main(){
    double x;
    scanf("%lf", &x);
    double result = ((x*x*x)-20.) / (x-7.);
    printf("%lf", result);
    return 0;
}