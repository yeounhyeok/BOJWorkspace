#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
    int n, t, x1, y1, x2, y2, cnt, cx, cy, r;
    cin>>t;
    for(int i=1;i<=t;i++){
        cnt=0;
        cin>>x1>>y1>>x2>>y2;
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>cx>>cy>>r;
            if((x1-cx)*(x1-cx)+(y1-cy)*(y1-cy)>=r*r&&(x2-cx)*(x2-cx)+(y2-cy)*(y2-cy)<r*r) cnt++;
            if((x1-cx)*(x1-cx)+(y1-cy)*(y1-cy)<r*r&&(x2-cx)*(x2-cx)+(y2-cy)*(y2-cy)>=r*r) cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}


