#include <bits/stdc++.h>
using namespace std;

bool visited0[100][100], visited1[100][100];
char arr[100][100];
int n, cnt0, cnt1;

void dfs0(int row, int col, char color, int depth){
    visited0[row][col] = true;
    if(depth==1) cnt0++;
    if(row+1<n && arr[row+1][col]==color && !visited0[row+1][col]) dfs0(row+1, col, color, depth+1);
    if(col+1<n && arr[row][col+1]==color && !visited0[row][col+1]) dfs0(row, col+1, color, depth+1);
    if(row-1>=0 && arr[row-1][col]==color && !visited0[row-1][col]) dfs0(row-1, col, color, depth+1);
    if(col-1>=0 && arr[row][col-1]==color && !visited0[row][col-1]) dfs0(row, col-1, color, depth+1);
}

void dfs1(int row, int col, char color, int depth){
    visited1[row][col] = true;
    if(depth==1) cnt1++;
    if(row+1<n && (arr[row+1][col]==color || abs(arr[row+1][col]-color)==11) && !visited1[row+1][col]) dfs1(row+1, col, color, depth+1);
    if(col+1<n && (arr[row][col+1]==color || abs(arr[row][col+1]-color)==11) && !visited1[row][col+1]) dfs1(row, col+1, color, depth+1);
    if(row-1>=0 && (arr[row-1][col]==color || abs(arr[row-1][col]-color)==11) && !visited1[row-1][col]) dfs1(row-1, col, color, depth+1);
    if(col-1>=0 && (arr[row][col-1]==color || abs(arr[row][col-1]-color)==11) && !visited1[row][col-1]) dfs1(row, col-1, color, depth+1);
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            if(!visited0[i][j]) dfs0(i, j, arr[i][j], 1);
            if(!visited1[i][j]) dfs1(i, j, arr[i][j], 1);
        }
    }
    cout<<cnt0<<' '<<cnt1;
    return 0;
}