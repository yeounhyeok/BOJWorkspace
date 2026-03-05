#include<bits/stdc++.h>
using namespace std;

int dx[][4] = {
    {0, 1, 2, 3}, //0
    {0, 0, 0, 0}, 
    {0, 1, 0, 1}, //1
    {0, 0, 0, 1}, //2
    {0, 0, 1, 2},
    {0, 1, 1, 1},
    {0, 1, 2, 2},
    {0, 1, 1, 1},
    {0, 0, 1, 2},
    {0, 1, 0, 0},
    {0, 1, 2, 2},
    {0, 0, 1, 1}, //3
    {0, 1, 1, 2},
    {0, 0, 1, 1},
    {0, 1, 1, 2},
    {0, 1, 2, 1}, //4
    {0, 1, 1, 1},
    {0, 1, 1, 2},
    {0, 0, 0, 1}
};

int dy[][4] = {
    {0, 0, 0, 0}, //0
    {0, 1, 2, 3}, 
    {0, 0, 1, 1}, //1
    {0, 1, 2, 2}, //2
    {1, 0, 0, 0},
    {0, 0, 1, 2},
    {0, 0, 0, -1},
    {0, 0, -1, -2},
    {0, 1, 1, 1},
    {0, 0, 1, 2},
    {0, 0, 0, 1},
    {0, 1, 1, 2}, //3
    {0, 0, -1, -1},
    {0, -1, -1, -2},
    {0, 0, 1, 1},
    {0, 0, 0, 1}, //4
    {0, -1, 0, 1},
    {0, -1, 0, 0},
    {0, 1, 2, 1}
};

int mx, arr[501][501], n, m,tx ;

bool chk(int i, int j, int t){
    for(int d=0;d<4;d++){
        if(j+dx[t][d]<0||j+dx[t][d]>=m||i+dy[t][d]>=n||i+dy[t][d]<0) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>arr[i][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int t=0;t<19;t++){ //terno shape
                if(chk(i, j, t)){
                    int cur = 0;
                    for(int ii=0;ii<4;ii++) cur+=arr[i+dy[t][ii]][j+dx[t][ii]];
                    mx = max(mx, cur);
                }
            }
        }
    }
    cout<<mx;
    return 0;
}