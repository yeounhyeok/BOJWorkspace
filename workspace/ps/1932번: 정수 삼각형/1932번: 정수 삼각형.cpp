#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<int> subv;

int n, a, ans[1002][1002];
int main(){
    
    cin>>n;

    for(int i=0;i<n;i++){
        subv.push_back(0);
        for(int j=1;j<=i+1;j++){
            cin>>a;
            subv.push_back(a);
        }
        subv.push_back(0);
        v.push_back(subv);
        vector<int>().swap(subv);
    }

    for(int i=1;i<=n+2;i++) subv.push_back(0);
    v.push_back(subv);

    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=i+1;j++){
            ans[i][j]=max(ans[i+1][j], ans[i+1][j+1])+v[i][j];
        }
    }

    cout<<ans[0][1];

    return 0;
}


