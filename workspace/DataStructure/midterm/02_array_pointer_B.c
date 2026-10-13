#include <stdio.h>

// [헷갈린 점] "함수 인자에 &가 들어가면 원본을 받는 것 아닌가?" -> 그건 C++의 참조(int &a).
// C에는 참조가 없고 인자는 항상 값 복사. 원본을 바꾸려면 호출할 때 &로 주소를 넘기고
// (add(x, y, &ans)), 받는 쪽은 포인터(int *ans)로 받아 *ans로 접근함.
void add(int x, int y, int *ans){
    *ans = x+y;
    return;
}

int main(){
    int x, y, ans;
    scanf("%d %d", &x, &y);
    add(x, y, &ans);
    printf("%d", ans);
    return 0;
}
