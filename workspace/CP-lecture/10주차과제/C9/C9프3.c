#include <stdio.h>
#include<math.h>

void qudratic(int a, int b, int c, double* xplus, double* xminus){
    *xminus = (-b - sqrt(b*b - 4*a*c)) / (2*a);
    *xplus = (-b + sqrt(b*b - 4*a*c)) / (2*a);
}

int main(){
    double a, b;
    qudratic(1, 4, 3, &a, &b);
    printf("첫 번째 실근    : %lf\n", a);
    printf("두 번째 실근    : %lf\n", b);
    return 0;
}