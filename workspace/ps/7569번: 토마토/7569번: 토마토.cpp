#include <bits/stdc++.h>
using namespace std;

short arr[105][105][105], N, M, H;
bool visited[105][105][105];
queue<tuple<int, int, int>> q;
vector<int> depth;

void bfs(){
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());

        visited[x][y][z] = true;

        if(x>0&&!visited[x-1][y][z]){
            q.push(make_tuple(x-1, y, z));
            visited[x-1][y][z] = true;
            depth[depth.size()-1]++;
        }
        if(x<M-1&&!visited[x+1][y][z]){
            q.push(make_tuple(x+1, y, z));
            visited[x+1][y][z] = true;
            depth[depth.size()-1]++;
        }
        if(y>0&&!visited[x][y-1][z]){
            q.push(make_tuple(x, y-1, z));
            visited[x][y-1][z] = true;
            depth[depth.size()-1]++;
        }
        if(y<N-1&&!visited[x][y+1][z]){
            q.push(make_tuple(x, y+1, z));
            visited[x][y+1][z] = true;
            depth[depth.size()-1]++;
        }
        if(z>0&&!visited[x][y][z-1]){
            q.push(make_tuple(x, y, z-1));
            visited[x][y][z-1] = true;
            depth[depth.size()-1]++;
        }
        if(z<H-1&&!visited[x][y][z+1]){
            q.push(make_tuple(x, y, z+1));
            visited[x][y][z+1] = true;
            depth[depth.size()-1]++;
        }

        q.pop();
        if(depth[depth.size()-2]==1&&q.size()!=0) {
            depth.push_back(0);
        }
        else depth[depth.size()-2]--;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>M>>N>>H;
    depth.push_back(0);
    for(int h=0;h<H;h++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>arr[j][i][h];
                if(arr[j][i][h]==1) {
                    q.push(make_tuple(j, i, h));
                    depth[0]++;
                }
                if(arr[j][i][h]==-1) visited[j][i][h] = true;
            }
        }
    }
    
    depth.push_back(0);
    bfs();

    int cnt=0, cnt1=0, cnt0=0;
    for(int h=0;h<H;h++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!visited[j][i][h]){
                    cout<<-1<<'\n';
                    return 0;
                }
                if(arr[j][i][h]==-1) cnt++;
                if(arr[j][i][h]==1) cnt1++;
                if(arr[j][i][h]==0) cnt0++;
            }
        }
    }

    if(cnt==N*M*H) {
        cout<<-1<<'\n';
        return 0;
    }

    if(cnt1==N*M*H||cnt0==0) {
        cout<<0<<'\n';
        return 0;
    }

    cout<<int(depth.size()-2)<<'\n';

    return 0;
}

