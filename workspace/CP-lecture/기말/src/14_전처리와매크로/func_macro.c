#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define DEBUG
#define PI 3.1415
#define CIRCLE_AREA(r) (PI*r*r)

int main(void)
{
    double radius, area;

#ifdef DEBUG
    printf("“디버깅 모드입니다.\n");
#endif

    printf("원의 반지름: ");
    scanf("%lf", &radius);
    area = CIRCLE_AREA(radius);
    printf("원의 면적=%.2f", area);

    return 0;
}
