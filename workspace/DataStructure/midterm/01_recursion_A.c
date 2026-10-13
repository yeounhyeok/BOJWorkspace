#include <stdio.h>

int sum(int cur, int n){
    if(!n) return cur;
    // [헷갈린 점] 처음엔 `cur = sum(cur+n, n-1);`만 쓰고 return을 빼먹었음.
    // 값을 반환하는 함수가 return 없이 끝나면 미정의 동작. -O0~-O3 gcc에선 우연히
    // eax에 값이 남아 정답이 나왔지만, 표준상 보장이 없고 -Werror 빌드에선 컴파일 실패.
    return sum(cur+n, n-1);
}

int main(){
    int N;
    scanf("%d", &N);
    printf("%d", sum(0, N));
    return 0;
}
