#include <stdio.h>
#include <stdlib.h>

int tmp, a[6];

int main(){
    for(int i=0;i<6e4;i++) a[rand()%6]++;
    for(int i=0;i<6;i++) printf("%d         %d\n", i+1, a[i]);
    return 0;
}