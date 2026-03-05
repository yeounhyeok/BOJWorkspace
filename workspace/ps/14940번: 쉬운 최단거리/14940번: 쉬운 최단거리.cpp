#include <bits/stdc++.h>

using namespace std;

int arr[1010][1010], result[1010][1010];
vector<int> depth;
queue<pair<int , int>> q;
bool visited[1010][1010];int n, m, x, y;

void bfs(){
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        visited[y][x] = true;
        result[y][x] = depth.size()-2;
        
        if(x>0&&arr[y][x-1]==1&&!visited[y][x-1]){
            q.push(make_pair(y, x-1));
            visited[y][x-1] = true;
            depth[depth.size()-1]++;
        }
        if(x<m-1&&arr[y][x+1]==1&&!visited[y][x+1]){
            q.push(make_pair(y, x+1));
            visited[y][x+1] = true;
            depth[depth.size()-1]++;
        }
        if(y>0&&arr[y-1][x]==1&&!visited[y-1][x]){
            q.push(make_pair(y-1, x));
            visited[y-1][x] = true;
            depth[depth.size()-1]++;
        }
        if(y<n-1&&arr[y+1][x]==1&&!visited[y+1][x]){
            q.push(make_pair(y+1, x));
            visited[y+1][x] = true;
            depth[depth.size()-1]++;
        }
        q.pop();
        if(depth[int(depth.size()-2)]==1&&q.size()!=0) {
            depth.push_back(0);
        }
        else depth[depth.size()-2]--;
        
    }
   
}


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m; //n -> y , m - >x    arr[y][x]
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2) q.push(make_pair(i, j));
        }
    }
    depth.push_back(1);
    depth.push_back(0);
    bfs();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1&&result[i][j]==0) result[i][j]=-1;
            cout<<result[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}