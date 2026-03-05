#include <bits/stdc++.h>
using namespace std;

vector<int> cnttmp;
bool arr[55][55];
char c[50];
bool visited[55][55];
int cnt;


void check(int a, int b, bool init, int t){
    if(arr[a][b]&&!visited[a][b]){ 
        if(init){
            cnt++;
            cnttmp.push_back(0);
        }  
        cnttmp[cnt]++;  
        visited[a][b] = true;
        check(a+1, b, false, t);
        check(a, b+1, false, t);
        if(b>0)check(a, b-1, false, t);
        if(a>0)check(a-1, b, false, t);
    }
}

int main(){
    int N;
    cin>>N;
    
    for(int j=0;j<N;j++){
        cin>>c;
        for(int i=0;i<N;i++){
            if(c[i]=='1') arr[i][j] = true; //arr[x][y]
        }    
        
    }

    cnttmp.push_back(0); //dummy
    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            check(a, b, true, 1);
        }
    }
    
    cout<<cnt<<'\n';
    sort(cnttmp.begin(), cnttmp.end());
    for(int i=1;i<cnttmp.size();i++) cout<<cnttmp[i]<<'\n';
    return 0;
}

