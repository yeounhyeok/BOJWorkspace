#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, min6=INT_MAX, cur=0, min1=INT_MAX;cin>>n>>m;
    for(int i=0;i<m;i++) {
        int a, b;cin>>a>>b;
        if(a<min6) min6 = a;
        if(b<min1) min1 = b;
    }
    int result=0;
    while(n>cur+6){
        result+=min6;
        cur+=6;
    }
    result = min(min1*n, min(result+min6, result+(n-cur)*min1));
    cout<<result;
    

    return 0;
}