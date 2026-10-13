#include <stdio.h>

// [헷갈린 점 1] 인덱스 p를 char로 둠. "포인터 + n은 자료형 크기만큼 이동"은 맞지만
// 그 크기는 포인터(char *a)의 타입이 정하고, 오프셋 p의 타입과는 무관함.
// p는 그냥 정수라 int가 안전함. char는 127을 넘으면 오버플로(길이 128+ 문자열에서 깨짐).
void rev(char *a, char p){
    printf("%c", *(a+p));
    if(!p) return;
    rev(a, p-1);
}

int main(){
    char a[105], p=0;
    fgets(a, sizeof(a), stdin);
    // [헷갈린 점 2 - 아직 안 고침] fgets는 끝의 '\n'까지 배열에 담음.
    // 그래서 --p가 '\n'을 가리켜 출력 맨 앞에 줄바꿈이 하나 나옴.
    // 고치려면: for(; a[p] != '\0' && a[p] != '\n'; p++);
    for(;*(a+p) != '\0';p++);
    rev(a, --p);
    return 0;
}
