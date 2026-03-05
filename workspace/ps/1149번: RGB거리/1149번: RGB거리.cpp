#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<int> findMin, subv;

int n, a, b, c, ans[1002][3];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        subv.push_back(a);
        subv.push_back(b);
        subv.push_back(c);
        v.push_back(subv);
        vector<int>().swap(subv);
    }

    for(int i=1;i<=n;i++){
        ans[i][0]=min(ans[i-1][1], ans[i-1][2])+v[i-1][0];
        ans[i][1]=min(ans[i-1][0], ans[i-1][2])+v[i-1][1];
        ans[i][2]=min(ans[i-1][0], ans[i-1][1])+v[i-1][2];
    }

    cout<<min(min(ans[n][0], ans[n][1]), ans[n][2]);

    return 0;
}


