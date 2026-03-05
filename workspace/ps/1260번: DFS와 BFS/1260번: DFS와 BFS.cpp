#include <bits/stdc++.h>

using namespace std;

typedef struct myNode{
  bool visited = false;
  int val;
  vector<myNode*> edges;
}myNode;

vector<myNode*> d_nodeArr;
vector<myNode*> b_nodeArr;
queue<myNode*> q;

bool cmp(myNode* a, myNode* b){
    return (a->val)<(b->val);
}

int cnt;
int order_arr[100001];

void dfs(myNode* node){
  if(node->visited) return;
  else{
    cout<<node->val<<" ";
    node->visited=true;
    cnt++;
    order_arr[node->val]=cnt;
  }
  
  sort(node->edges.begin(), node->edges.end(), cmp);
  for(int i=0;i<node->edges.size();i++) dfs(node->edges[i]);
}

void bfs(myNode *node, unsigned long long level) {
  q.front()->visited=true;
  while(q.size()>0){
    
    myNode* tmp = q.front();
    cout<<tmp->val<<" ";
    q.pop();

    sort(tmp->edges.begin(), tmp->edges.end(), cmp);
    for(int i=0;i<tmp->edges.size();i++){
      if(!tmp->edges[i]->visited){
        q.push(tmp->edges[i]);
        tmp->edges[i]->visited = true;    
        //cout<<tmp->edges[i]->val<<" "; 
      }
    }
    cnt++;
    order_arr[tmp->val] = cnt;
    
  }
  
}


int main(){
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  //myNode* currentNode = new myNode;

  int n, m, r, u, v;cin>>n>>m>>r;

  for(int i=0;i<=n;i++){  //val 0 node is dummy
    myNode* d_tmp = new myNode;
    myNode* b_tmp = new myNode;
    d_tmp->val=i;
    b_tmp->val=i;
    d_nodeArr.push_back(d_tmp);
    b_nodeArr.push_back(b_tmp);
  }

  myNode* d_headNode = d_nodeArr[r];
  myNode* b_headNode = b_nodeArr[r];

  for(int i=0;i<m;i++){
    cin>>u>>v;
    d_nodeArr[u]->edges.push_back(d_nodeArr[v]);
    d_nodeArr[v]->edges.push_back(d_nodeArr[u]);
    b_nodeArr[u]->edges.push_back(b_nodeArr[v]);
    b_nodeArr[v]->edges.push_back(b_nodeArr[u]);
  }
  
  dfs(d_headNode);
  cout<<"\n";
  q.push(b_headNode);
  bfs(q.front(), 0);
  

  return 0;
}

