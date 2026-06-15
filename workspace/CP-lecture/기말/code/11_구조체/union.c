#include <stdio.h>

union example {
    int i;
    char c;
};

int main(void)
{
    union example data;

    data.c = 'A';
    printf("data.c:%c   data.i:%i\n", data.c, data.i);

    data.i = 10000;
    printf("data.c:%c   data.i:%i\n", data.c, data.i);

}
