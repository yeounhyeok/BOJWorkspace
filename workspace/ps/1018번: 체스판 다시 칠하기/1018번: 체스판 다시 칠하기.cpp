#include <bits/stdc++.h>

using namespace std;

int n, m, cnt[10000];
string arr[55];
string ans1[9];
string ans2[9];
int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin>>n>>m;

    for(int j=1;j<=n;j++){
        cin>>arr[j];
    }

    for(int i=1;i<=8;i+=2){
        ans1[i]="BWBWBWBW";
        ans1[i+1]="WBWBWBWB";
    }
    for(int i=1;i<=8;i+=2){
        ans2[i]="WBWBWBWB";
        ans2[i+1]="BWBWBWBW";
    }
    int p=0;
    for(int k=0;k<n-7;k++){
        for(int l=0;l<m-7;l++){
            for(int i=1;i<=8;i++){
                for(int j=0;j<8;j++){
                    if(ans1[i][j]!=arr[k+i][l+j]) cnt[p]++;
                    if(ans2[i][j]!=arr[k+i][l+j]) cnt[p+1]++;
                }
            }
            p+=2;
        }
    }

    sort(cnt, cnt+(2*(n-7)*(m-7)));

    cout<<cnt[0];

    return 0;
}