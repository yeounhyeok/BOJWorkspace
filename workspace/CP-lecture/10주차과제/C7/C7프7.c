#include <stdio.h>

int main(){
    int n=3, a[3][3], b[3][3];
    
    printf("행 개수=3\n열 개수=3\n첫 번째 행렬 입력=\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("두 번째 행렬 입력=\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &b[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum=0;
            for(int k=0;k<n;k++) sum+=(a[i][k]*b[k][j]);
            printf("%d ", sum);
        }
        printf("\n");
    }

    return 0;
}