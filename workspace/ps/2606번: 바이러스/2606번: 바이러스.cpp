#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, cnt;

typedef struct Node{
    vector<Node*> edges;
    bool visited = false;
}Node;

queue<Node*> q;

void bfs(){
    while(!q.empty()){
        for(int i=0;i<q.front()->edges.size();i++){
            if((q.front()->edges[i]->visited) == false){
                q.push(q.front()->edges[i]);
                q.front()->edges[i]->visited = true;
                cnt++;
            } 
        }
        q.pop();
    }
}

Node* nodes[105];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        nodes[i] = new Node;
    }
    
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        nodes[a]->edges.push_back(nodes[b]);
        nodes[b]->edges.push_back(nodes[a]);
    }

    q.push(nodes[1]);
    nodes[1]->visited = true;
    bfs();
    cout<<cnt<<'\n';
    return 0;
}

