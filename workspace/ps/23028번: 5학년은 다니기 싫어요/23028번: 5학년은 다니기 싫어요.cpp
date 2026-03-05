#include <bits/stdc++.h>
using namespace std;

int main(){
    int mx, n, a, b, arr[10][2];
    cin>>n>>a>>b;
    for(int i=0;i<10;i++) cin>>arr[i][0]>>arr[i][1];
    for(int i=0;i<8-n;i++){
            a+=arr[i][0]*3;
            b+=arr[i][0]*3;
            b+=((6-arr[i][0]<arr[i][1]) ? 6-arr[i][0]:arr[i][1])*3;
    }
    if(a>=66 && b>=130) cout<<"Nice";
    else cout<<"Nae ga wae";

    return 0;
}