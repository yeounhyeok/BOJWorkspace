#include <stdio.h>

enum days { MON, TUE, WED, THU, FRI, SAT, SUN };

// 포인터들의 배열을 만들고 문자열 상수로 초기화한다.
char *days_name[] = {
    "monday", "tuesday", "wednesday", "thursday", "friday",
    "saturday", "sunday" };

int main(void)
{
    enum days d;

    for (d = MON; d <= SUN; d++)
        printf("%d번째 요일의 이름은 %s입니다\n", d, days_name[d]);
    return 0;
}
