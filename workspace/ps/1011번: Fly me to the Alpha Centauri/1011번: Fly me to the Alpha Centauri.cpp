#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    double gap;int t, x, y;cin>>t;
    for(int i=0;i<t;i++){
        cin>>x>>y;gap=y-x;
        cout<<floor(sqrt(4*gap-1))<<'\n';
    }
    return 0;
}

