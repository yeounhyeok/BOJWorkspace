#include <bits/stdc++.h>

using namespace std;

typedef struct myNode{
  bool visited = false;
  int val;
  vector<myNode*> edges;
}myNode;

vector<myNode*> nodeArr;

bool cmp(myNode* a, myNode* b){
    return (a->val)>(b->val);
}

int cnt;
int order_arr[100001];

void dfs(myNode* node){
  if(node->visited) return;
  else{
    node->visited=true;
    cnt++;
    order_arr[node->val]=cnt;
  }
  
  sort(node->edges.begin(), node->edges.end(), cmp);
  for(int i=0;i<node->edges.size();i++) dfs(node->edges[i]);
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  //myNode* currentNode = new myNode;

  int n, m, r, u, v;cin>>n>>m>>r;

  for(int i=0;i<=n;i++){  //val 0 node is dummy
    myNode* tmp = new myNode;
    tmp->val=i;
    nodeArr.push_back(tmp);
  }

  myNode* headNode = nodeArr[r];

  for(int i=0;i<m;i++){
    cin>>u>>v;
    nodeArr[u]->edges.push_back(nodeArr[v]);
    nodeArr[v]->edges.push_back(nodeArr[u]);
  }
  
  dfs(headNode);
  
  for(int i=1;i<=n;i++) cout<<order_arr[i]<<'\n';

  return 0;
}

