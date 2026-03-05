#include<bits/stdc++.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
using namespace std;

int d[] = {1,0,-1,0,1}, arr[9][9], flag;

void print() {
    rep(i, 0, 9) {
        rep(j, 0, 9) cout<<arr[i][j]<<' '; 
        cout<<'\n';
    }
}

bool chk(int r, int c, int cur){
    rep(i, 3*(r/3), 3*(r/3)+3) {
        rep(j, 3*(c/3), 3*(c/3)+3) {
            if(!(i==r&&j==c)&&arr[i][j]==cur)return 0;
        }
    }
    rep(i, 0, 9) if(i!=r&&arr[i][c]==cur) return 0;
    rep(i, 0, 9) if(i!=c&&arr[r][i]==cur) return 0;
    return 1;
}

void dfs(int r, int c, int cur){
    if(!chk(r, c, cur)) return;
    rep(i, r, 9){
        rep(j, 0, 9){
            if(!arr[i][j]) {
                rep(tmp, 1, 10){
                    arr[i][j]=tmp;
                    dfs(i, j, tmp);
                    if(flag) return;
                    arr[i][j]=0;
                    if(tmp==9) return;
                }
            }
            else if(i==8&&j==8){
                flag=1;
                return;
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    rep(i, 0, 9) rep(j, 0, 9) cin>>arr[i][j];
    rep(i, 0, 9){
        rep(j, 0, 9){
            if(!arr[i][j]) {
                rep(tmp, 1, 10){
                    arr[i][j]=tmp;
                    dfs(i, j, tmp);
                    if(flag) {
                        print();
                        return 0;
                    }
                    arr[i][j]=0;
                }
            }
        }
    }
    return 0;   
}
