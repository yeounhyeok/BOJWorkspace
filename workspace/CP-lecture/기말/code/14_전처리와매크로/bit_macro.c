// 매크로 예제
#include <stdio.h>
#define SETBIT(x, n)   ((x) |= (1<<(n)))
#define CLEARBIT(x, n) ((x) &= ~(1<<(n)))
#define TESTBIT(x, n)  ((x) & (1<<(n)))

int main(void)
{
    int x = 0x1011;


    printf("SETBIT(x, 8)전 변수 x = %x\n", x);
    SETBIT(x, 8);
    printf("SETBIT(x, 8)후 변수 x = %x\n", x);

    printf("CLEARBIT(x, 8)전 변수 x = %x\n", x);
    CLEARBIT(x, 8);
    printf("CLEARBIT(x, 8)후 변수 x = %x\n", x);

    return 0;
}
