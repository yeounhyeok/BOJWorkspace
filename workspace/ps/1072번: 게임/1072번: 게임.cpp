#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll x, y, z;
    cin>>x>>y;
    z=((y*100)/x);
    ll s=0, e=1e9+1, m, ans=0;
    while(s+1<e){
        m=(s+e)/2;
        ll tmpz=(((m+y)*100)/(m+x));
        if(tmpz<=z){
            s=m;
            ans=s;
        }
        else e=m;
    }
    cout<<(e>1e9?-1:e);
    return 0;
}