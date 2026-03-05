#include <bits/stdc++.h>

using namespace std;

typedef struct myNode {
  bool visited = false;
  int val;
  vector<myNode *> edges;
} myNode;

vector<myNode*> nodeArr;
queue<myNode*> q;

bool cmp(myNode *a, myNode *b) { return (a->val) < (b->val); }

unsigned long long cnt=0;
long long order_arr[100001], level_arr[100001];

void bfs(myNode *node, unsigned long long level) {
  q.front()->visited=true;
  while(q.size()>0){
    
    myNode* tmp = q.front();
    q.pop();

    sort(tmp->edges.begin(), tmp->edges.end(), cmp);
    for(int i=0;i<tmp->edges.size();i++){
      if(!tmp->edges[i]->visited){
        q.push(tmp->edges[i]);
        tmp->edges[i]->visited = true;     
      }
    }
    cnt++;
    order_arr[tmp->val] = cnt;
    level_arr[tmp->val] = level;
  }
  
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, r, u, v;
  cin >> n >> m >> r;

  for (int i = 0; i <= n; i++) { // val 0 node is dummy
    myNode *tmp = new myNode;
    tmp->val = i;
    nodeArr.push_back(tmp);
  }

  myNode *headNode = nodeArr[r];

  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    nodeArr[u]->edges.push_back(nodeArr[v]);
    nodeArr[v]->edges.push_back(nodeArr[u]);
  }

  q.push(headNode);
  bfs(q.front(), 0);

  for (int i = 1; i <= n; i++)
    cout << order_arr[i] << '\n';
  return 0;
}
