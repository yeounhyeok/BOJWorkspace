#include <bits/stdc++.h>
#define _C 5000
#define MX 10001
using namespace std;

bool v[10002][10002];
int result[50][50];
int cnt=2, r, c;

int main(){
    ios::sync_with_stdio(0);cout.tie(0);

    v[_C][_C] = true; v[_C][1+_C]=true;
    r = _C; c = 1+_C;

    int r1, c1, r2, c2;cin>>r1>>c1>>r2>>c2;
    int outputMax = (r2-r1+1) * (c2-c1+1), outputCnt=0;
    for(int i=0;i<2;i++){
        if(_C>=r1+_C && _C<=r2+_C && i+_C>=c1+_C && i+_C<=c2+_C){
            v[_C][i+_C] = true;
            result[_C-(r1+_C)][i+_C-(c1+_C)] = 1+i;
        }
    }

    while(cnt<=MX*MX){

        while(c>0 && v[r][c-1] && outputCnt <= outputMax) {
            if(r-1>=r1+_C && r-1<=r2+_C && c>=c1+_C && c<=c2+_C){
                v[--r][c] = true;
                result[r-(r1+_C)][c-(c1+_C)] = ++cnt;
                outputCnt++;
            }
            else{
                cnt++;
                v[--r][c] = true;
            }
        }
        while(r<MX && v[r+1][c]) {
            if(r>=r1+_C && r<=r2+_C && c-1>=c1+_C && c-1<=c2+_C){
                v[r][--c] = true;
                result[r-(r1+_C)][c-(c1+_C)] = ++cnt;
                outputCnt++;
            }
            else{
                cnt++;
                v[r][--c] = true;
            }
        }
        while(c<MX && v[r][c+1]) {
            if(r+1>=r1+_C && r+1<=r2+_C && c>=c1+_C && c<=c2+_C){
                v[++r][c] = true;
                result[r-(r1+_C)][c-(c1+_C)] = ++cnt;
                outputCnt++;
            }
            else{
                cnt++;
                v[++r][c] = true;
            }
        }
        while(r>0 && v[r-1][c]) {
            if(r>=r1+_C && r<=r2+_C && c+1>=c1+_C && c+1<=c2+_C){
                v[r][++c] = true;
                result[r-(r1+_C)][c-(c1+_C)] = ++cnt;
                outputCnt++;
            }
            else{
                cnt++;
                v[r][++c] = true;
            }
        }

    }

    int n, mx = 0;  
    for(int i=0;i<=r2-r1;i++) {
        for(int j=0;j<=c2-c1;j++) {
            if(mx < result[i][j]) {
                mx = result[i][j];
            }
        }
    }
    int mxlen = to_string(mx).length();


    for(int i=0;i<=r2-r1;i++){
        for(int j=0;j<=c2-c1;j++){
            n = mxlen - to_string(result[i][j]).length();
            for(int k=0;k<n;k++) cout<<' ';
            cout<<result[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
