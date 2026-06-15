#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double FtoC(double temp_f); // 함수 원형 정의

int  main(void)
{
    double c, f;
    f = 32.0;
    c = FtoC(f);            // 함수 호출
    printf("화씨온도 %f은 섭씨온도 %f에 해당한다. \n", f, c);
    return 0;
}

double FtoC(double temp_f)  // 함수 정의
{
    double  temp_c;
    temp_c = (5.0 * (temp_f - 32.0)) / 9.0;
    return temp_c;
}
