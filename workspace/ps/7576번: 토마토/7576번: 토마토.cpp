#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005], N, M;
bool visited[1005][1005];
queue<pair<short, short>> q;
vector<int> depth;

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = true;
        if(x>0&&!visited[x-1][y]){
            q.push(make_pair(x-1, y));
            visited[x-1][y] = true;
            depth[depth.size()-1]++;
        }
        if(x<M-1&&!visited[x+1][y]){
            q.push(make_pair(x+1, y));
            visited[x+1][y] = true;
            depth[depth.size()-1]++;
        }
        if(y>0&&!visited[x][y-1]){
            q.push(make_pair(x, y-1));
            visited[x][y-1] = true;
            depth[depth.size()-1]++;
        }
        if(y<N-1&&!visited[x][y+1]){
            q.push(make_pair(x, y+1));
            visited[x][y+1] = true;
            depth[depth.size()-1]++;
        }
        q.pop();
        if(depth[int(depth.size()-2)]==1&&q.size()!=0) {
            depth.push_back(0);
        }
        else depth[depth.size()-2]--;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>M>>N;
    depth.push_back(0);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[j][i];
            if(arr[j][i]==1) {
                q.push(make_pair(j, i));
                depth[0]++;
            }
            if(arr[j][i]==-1) visited[j][i] = true;
        }
    }
    
    depth.push_back(0);
    bfs();

    int cnt=0, cnt1=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!visited[j][i]){
                cout<<-1<<'\n';
                return 0;
            }
            if(arr[j][i]==-1) cnt++;
            if(arr[j][i]==1) cnt1++;
        }
    }

    if(cnt==N*M) {
        cout<<-1<<'\n';
        return 0;
    }

    if(cnt1==N*M) {
        cout<<0<<'\n';
        return 0;
    }

    cout<<int(depth.size()-2)<<'\n';

    return 0;
}

