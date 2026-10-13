#include <stdio.h>
#define ll long long

ll mul(ll cur, ll x, ll n){
    if(!n) return cur;
    return mul(cur*x, x, n-1);
}

int main(){
    ll x, n;
    scanf("%lld %lld", &x, &n);
    // [헷갈린 점] 처음엔 `n ? mul(1, x, n) : 0`으로 썼음 -> n=0일 때 0 출력(오답).
    // x^0 = 1이고, mul(1, x, 0)이 종료 조건에서 cur(=1)를 그대로 반환하므로
    // 삼항 연산자로 n=0을 따로 처리할 필요가 없었음. (경계값: n=0, x=0이어도 1)
    printf("%lld", mul(1, x, n));
    return 0;
}
