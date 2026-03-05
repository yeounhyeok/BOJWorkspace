#include<bits/stdc++.h>
#define MX 4000001
using namespace std;
typedef unsigned long long ull;
typedef vector<ull> vi;

bool arr[MX];

vi era(int n){
    vi res(1);
    for(int i=2;i<=n;i++){
        for(int j=i*2;j<=n;j+=i){
            arr[j]=1;
        }
    }
    for(int i=2;i<=n;i++)if(!arr[i]) {
        res.push_back(i);
        res[res.size()-1]+=res[res.size()-2];
    }
    return res;
}

int main(){
    ull n, cnt=0;cin>>n;
    vi e = era(n);
    ull lt=0, rt=1;
    while(lt<rt){
        ull cur = e[rt]-e[lt];
        if(cur<n) rt++;
        else if(cur>n) lt++;
        else {
            cnt++;
            lt++;
        }
    }
    cout<<cnt;
    return 0;
}