#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
unsigned long long arr[35][35];

int main(){
    cin.tie(NULL);ios_base::sync_with_stdio(false);
    int n, m, k;
    cin>>k;
    for(int l=1;l<=k;l++){
        cin>>n>>m;
        for(int i=1;i<30;i++){
            arr[1][i]=i;
            arr[i][i]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++){
                arr[i][j]=arr[i-1][j-1]+arr[i][j-1];
            }
        }
        cout<<arr[n][m]<<'\n';
    }
}


