#include <stdio.h>

int a;
int main(){
    scanf("%d", &a);
    if(a>=90) printf("A");
    else if(a<90&&a>=80) printf("B");
    else if(a<80&&a>=70) printf("C");
    else if(a<70&&a>=60) printf("D");
    else printf("F");
}


