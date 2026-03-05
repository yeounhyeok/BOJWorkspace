#include <bits/stdc++.h>
#define p 1500000
using namespace std;
typedef long long ull;


int main(){
    ull n;cin>>n;
    int v[p+1];v[0]=0;v[1]=1;
    for(int i=2;i<=p;i++) v[i]=((v[i-1]+v[i-2])%1000000);
    cout<<v[n%p];
    return 0;
}