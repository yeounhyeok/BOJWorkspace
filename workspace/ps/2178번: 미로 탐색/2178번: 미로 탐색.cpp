#include <bits/stdc++.h>

using namespace std;

char arr[105][105];
vector<int> depth;
queue<pair<int , int>> q;
bool visited[105][105];int n, m;

void bfs(){
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        visited[y][x] = true;
        if(y==n-1&&x==m-1) return;
        if(x>0&&arr[y][x-1]=='1'&&!visited[y][x-1]){
            q.push(make_pair(y, x-1));
            visited[y][x-1] = true;
            depth[depth.size()-1]++;
        }
        if(x<m-1&&arr[y][x+1]=='1'&&!visited[y][x+1]){
            q.push(make_pair(y, x+1));
            visited[y][x+1] = true;
            depth[depth.size()-1]++;
        }
        if(y>0&&arr[y-1][x]=='1'&&!visited[y-1][x]){
            q.push(make_pair(y-1, x));
            visited[y-1][x] = true;
            depth[depth.size()-1]++;
        }
        if(y<n-1&&arr[y+1][x]=='1'&&!visited[y+1][x]){
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
        cin>>arr[i];
    }
    depth.push_back(1);
    depth.push_back(0);
    q.push(make_pair(0, 0));
    bfs();

    cout<<depth.size()-1<<'\n';

    return 0;
}