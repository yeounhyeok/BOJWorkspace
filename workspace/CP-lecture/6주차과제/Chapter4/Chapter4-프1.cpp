#include <stdio.h>

int main(){
    double w, h;
    printf("체중을 입력하시오: ");
    scanf("%lf", &w);
    printf("신장을 입력하시오: ");
    scanf("%lf", &h);
    printf("BMI: %lf\n", w / (h*h) );
    return 0;
}