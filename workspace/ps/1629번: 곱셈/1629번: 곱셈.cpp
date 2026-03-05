#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dpow(ll a, ll b, ll c) {
	if (b == 1) { 
		return a % c;
	}
	ll tmp = dpow(a, b/2, c) % c;
	if( b % 2 == 0 ){
		return tmp * tmp % c;
	}
	else {
		return tmp * tmp % c * a % c;
	}
}

int main(){
    int a,b,c;cin>>a>>b>>c;
    cout<<dpow(a,b,c);
    return 0;
}