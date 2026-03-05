#include <bits/stdc++.h>
using namespace std;

int arr[51][51], d[] = {-1, 0, 1, 0, -1}, cnt;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int r, c, a, b, to;cin>>r>>c>>a>>b>>to;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>arr[i][j];
    while(1){
        there:
        if(!arr[a][b]) {
            arr[a][b]=2;
            cnt++;
        }
        for(int i=0;i<4;i++){
            int nexta = a+d[i], nextb = b+d[i+1];
            if((nexta>=0&&nexta<r&&nextb>=0&&nextb<c) && arr[nexta][nextb]==0){
                to = (to ? to-1:3);
                if(!arr[a+d[to]][b+d[to+1]]){
                    a+=d[to];
                    b+=d[to+1];
                }
                goto there;
            }
        }

        int backward = to<2 ? to+2:to-2;
        if(arr[a+d[backward]][b+d[backward+1]]!=1){
            a+=d[backward];
            b+=d[backward+1];
        }
        else break;
    }
    cout<<cnt;
    return 0;
}