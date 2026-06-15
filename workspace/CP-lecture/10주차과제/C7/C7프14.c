#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main(){
    double a[5], sum=0, sum2=0, mu, std;
    for(int i=0;i<5;i++) {
        printf("실수를 입력하시오: ");
        scanf("%lf", a+i);
        sum+=a[i];
    }
    mu = (1./5.) * sum;
    for(int i=0;i<5;i++) sum2+=((a[i]-mu)*(a[i]-mu));
    std = sqrt((1./5.) * sum2);

    printf("평균:%lf\n표준편차:%lf", mu, std);

    return 0;
}