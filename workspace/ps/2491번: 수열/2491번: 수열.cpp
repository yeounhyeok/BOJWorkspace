#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n, cntup=1, cntdwn=1, mxup=0, mxdwn=0;
    cin>>n;
    vector<int> v(n);
    
    cin>>v[0];
    for(int i=1;i<n;i++) {
        cin>>v[i];
        if(v[i]>v[i-1]) {
            cntup++;
            if(cntdwn>mxdwn) mxdwn = cntdwn;
            cntdwn = 1;
        }
        else if(v[i]<v[i-1]) {
            cntdwn++;
            if(cntup>mxup) mxup = cntup;
            cntup = 1;
        }
        else{
            cntup++;
            cntdwn++;
        }
    }

    if(cntup>mxup) mxup = cntup;
    if(cntdwn>mxdwn) mxdwn = cntdwn;
    cout<<max(mxup, mxdwn)<<'\n';

    return 0;
}