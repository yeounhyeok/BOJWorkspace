#include <bits/stdc++.h>

using namespace std;

int arr[100005];

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    for(int i=1;i<=10000;i++){
        arr[i+i%10+i/10%10+i/100%10+i/1000%10+i/10000%10]=1;
    }
    for(int i=1;i<=10000;i++){
        if(arr[i]==0) cout<<i<<'\n';
    }
    return 0;
}