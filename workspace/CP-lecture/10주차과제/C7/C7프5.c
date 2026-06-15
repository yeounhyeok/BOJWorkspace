#include <stdio.h>

int main(){
    int arr[4][4] = {
        {0, 0, 0, 0},
        {0, 30, 10, 11},
        {0, 40, 90, 32},
        {0, 70, 65,56}
    };

    for(int i=1;i<4;i++){
        int sum = 0;
        for(int j=1;j<4;j++) sum+=arr[i][j];
        printf("%lf\n", sum/3.);
    }

    return 0;
}