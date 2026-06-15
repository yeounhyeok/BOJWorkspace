#include <stdio.h>

int main(){
    double w, h;
    printf("상품 가격을 입력하시오: ");
    scanf("%lf", &w);
    printf("할인율을 입력하시오: ");
    scanf("%lf", &h);
    printf("할인된 가격은 %lf입니다.\n", w - w * (h/100.));
    return 0;
}