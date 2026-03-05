#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ull sum, tmp, n, m, s=0, e=0, md, ans;cin>>n>>m;
    vector<ull> v;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
        if(e<tmp) e = tmp;
    }   
    while(s<=e){
        md = (s+e)/2ULL;
        sum=0;
        for(auto i:v) {
            sum+= i>=md ? i-md : 0ULL;
        }

        if(sum>=m) {
            s = md+1ULL;
            ans=md;
        }
        else e = md-1ULL;
    }
    cout<<ans;
    return 0;
}
