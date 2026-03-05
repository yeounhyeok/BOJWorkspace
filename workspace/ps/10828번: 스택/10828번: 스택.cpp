#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
  stack<int> q;
  string str="";
  int x, n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>str;
    if(str=="pop"){
      if(q.size()!=0){
        cout<<q.top()<<'\n';
        q.pop();
      }
      else cout<<-1<<'\n';
      str="";
    }
    else if(str=="size"){
      cout<<q.size()<<'\n';
    }
    else if(str=="empty"){
      cout<<q.empty()<<'\n';
      str="";
    }

    else if(str=="top"){
      if(q.size()!=0) cout<<q.top()<<'\n';
      else cout<<"-1"<<'\n';
      str="";
    }
    else{
      cin>>x;
      q.push(x);
    }
  }


  return 0;
}
