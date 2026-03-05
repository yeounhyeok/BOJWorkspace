#include <bits/stdc++.h>

using namespace std;

int arr[10005], n, d, cnt=0, x;

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin>>x;
    for(int i=1;i<=x;i++){
        n=0;
        d = i/10%10-i%10;
        for(int j=i;j/10!=0;){
            if(d==j/10%10-j%10) j/=10;
            else goto there;
        }
        arr[i]++;
        there:;
    }
    for(int i=1;i<=x;i++){
        if(arr[i]!=0) cnt++;
    }
    cout<<cnt;
    return 0;
}