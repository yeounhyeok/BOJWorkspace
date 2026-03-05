#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
  queue<int> q;
  string str="";
  int x, n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>str;
    if(str=="pop"){
      if(q.size()!=0){
        cout<<q.front()<<'\n';
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
    else if(str=="front"){
      if(q.size()!=0) cout<<q.front()<<'\n';
      else cout<<"-1"<<'\n';
      str="";
    }
    else if(str=="back"){
      if(q.size()!=0) cout<<q.back()<<'\n';
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