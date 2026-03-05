#include <bits/stdc++.h>
using namespace std;

int N, dt[1005];

int main(){
    cin>>N;
    dt[1]=1;dt[2]=2;
    for(int i=3;i<=N;i++) dt[i] = (dt[i-1]+dt[i-2])%10007;
    cout<<dt[N]%10007<<'\n';
    return 0;
}

