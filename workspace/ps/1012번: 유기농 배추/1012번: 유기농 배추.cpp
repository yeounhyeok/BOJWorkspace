#include <iostream>
using namespace std;

bool arr[55][55];
bool visited[55][55];
int cnt[110];

void check(int a, int b, bool init, int t){
    if(arr[a][b]&&!visited[a][b]){
        if(init) cnt[t]++;    
        visited[a][b] = true;
        check(a+1, b, false, t);
        check(a, b+1, false, t);
        if(b>0)check(a, b-1, false, t);
        if(a>0)check(a-1, b, false, t);
    }
}

int main(){
    int T, N, M, K, x, y;
    cin>>T;
    
    for(int i=0;i<T;i++){
        cin>>M>>N>>K;
        for(int j=0;j<K;j++){
            cin>>x>>y;
            arr[y][x] = true;
        }
        for(int a=0;a<N;a++){
            for(int b=0;b<M;b++){
                check(a, b, true, i);
            }
        }
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                arr[j][k]=false;
                visited[j][k]=false;
            }
        }
    }
    for(int i=0;i<T;i++) cout<<cnt[i]<<'\n';
    return 0;
}

