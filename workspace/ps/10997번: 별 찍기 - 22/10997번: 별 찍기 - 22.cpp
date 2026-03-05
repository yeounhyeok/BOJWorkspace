#include <bits/stdc++.h>

using namespace std;

int n, i, arr[400][410];

int main(){
    cin>>n;
    if(n==1){
        cout<<"*"<<'\n';
    }
    else{
        int x=4*n-3, y=1, dx=4*n-3, dy=4*(n-1)+3;
        
        for(i=x;i>=x-dx+1;i--) arr[i][y]++;
        x=x-dx+1;
        for(i=y;i<=y+dy-1;i++) arr[x][i]++;
        y=y+dy-1;
        for(i=x;i<=x+dx-1;i++) arr[i][y]++;
        x=x+dx-1;
        dy-=2;
        for(i=y;i>=y-dy+1;i--) arr[x][i]++;
        y=y-dy+1;
        dx-=2;
        dy-=2;
        
        while(1){
            for(i=x;i>=x-dx+1;i--) arr[i][y]++;
            x=x-dx+1;
            dx-=2;
            for(i=y;i<=y+dy-1;i++) arr[x][i]++;
            y=y+dy-1;
            dy-=2;
            if(arr[(4*n-3)/2+1][(4*(n-1)+3)/2+2]!=0) break;
            for(i=x;i<=x+dx-1;i++) arr[i][y]++;
            x=x+dx-1;
            dx-=2;
            for(i=y;i>=y-dy+1;i--) arr[x][i]++;
            y=y-dy+1;
            dy-=2;

        }
        for(i=1;i<=4*(n-1)+3;i++){
            if(i==2){
                cout<<"*\n";
                continue;
            }
            for(int j=1;j<=4*n-3;j++){
                if(arr[j][i]!=0) cout<<"*";
                else cout<<" ";
            }
            cout<<'\n';
        }
    }
    return 0;
}