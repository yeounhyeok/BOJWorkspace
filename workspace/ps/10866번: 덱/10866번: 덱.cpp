#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
  deque<int> q;
  string str="";
  int x, n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>str;
    if(str=="pop_back"){
      if(q.size()!=0){
        cout<<q.back()<<'\n';
        q.pop_back();
      }
      else cout<<-1<<'\n';
      str="";
    }
    else if(str=="pop_front"){
      if(q.size()!=0){
        cout<<q.front()<<'\n';
        q.pop_front();
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
        if(str=="push_front") q.push_front(x);
        else q.push_back(x);
    }
    str="";
  }
  
  
  return 0;
}