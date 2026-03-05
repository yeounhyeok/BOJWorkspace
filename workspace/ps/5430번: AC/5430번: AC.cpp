#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

deque<int> v;
string command, arr, subs;

int main(){
  int n, k;
  bool error=false, reversed=false;

  cin>>n;
  for(int i=1;i<=n;i++){
    reversed=false;error=false;
    cin>>command>>k>>arr;
    for(int j=0;arr.length()>j;j++){
        while(arr[j]!=','&&arr[j]!=']'){
            if(arr[j]>='0'&&arr[j]<='9'){
                subs+=arr[j];
            }
            if(arr.length()>=j) j++;
        }
        if(subs!="")v.push_back(stoi(subs));
        subs="";
    }
    for(int j=0;command[j]!='\0';j++){
        if(command[j]=='R'){
            reversed = !reversed;
        }
        else if(command[j]=='D'){
            if(v.size()!=0){
                if(!reversed) v.pop_front();
                else v.pop_back();
            }
            else{
                error=true;
                break;
            }
        }
    }
    if(error){
        cout<<"error"<<'\n';
        goto there;
    }
    if(v.size()==0){
        cout<<"[]"<<'\n';
        continue;
    }
    cout<<"[";
    if(reversed==true){
        for(int j=v.size()-1;j>=1;j--){
            cout<<v[j]<<",";
        }
        cout<<v[0]<<"]\n";
    }
    else{
        for(int j=0;j<v.size()-1;j++){
            cout<<v[j]<<",";
        }
        cout<<v[v.size()-1]<<"]\n";
    }
    
    v.clear();
    command="";arr="";
    there:;
  }


  return 0;
}

