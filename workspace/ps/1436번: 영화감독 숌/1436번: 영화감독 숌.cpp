#include <bits/stdc++.h>

using namespace std;

int n, cnt=0, cnt2=0, temp;
int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin>>n;
    if(n==1){
        cout<<666;
        return 0;
    }
    n-=2;
    int i;
    for(i=1665;cnt<=n;i++){
        cnt2=0;
        temp=i;
        for(;temp!=0;){
            if(cnt2==1){
                cnt++;
                break;
            }
            if((temp-666)%1000==0) cnt2=1;
            else temp/=10;
        } 
    }
    cout<<i-1;

    return 0;
}