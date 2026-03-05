#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main(){
    ull ans, n, s=0, e=1ULL<<32, mid;cin>>n;
    while(s<e){
        mid = (s+e)/2ULL;
        if(mid*mid<n) s = mid+1ULL;
        else e = mid;
    }
    cout<<s;
    return 0;
}