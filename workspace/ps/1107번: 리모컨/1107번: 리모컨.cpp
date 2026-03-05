#include <bits/stdc++.h>
#define MAX 2147483647

using namespace std;
vector<int> v;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

  int ch, min=MAX;cin>>ch;
  int n, tmp;cin>>n;
  for(int i=1;i<=n;i++){
    cin>>tmp;
    v.push_back(tmp);
  }

  if(ch>100){
    if(ch-100<min) min=ch-100;
  }
  else{
    if(100-ch<min) min=100-ch;
  }
  string chStr, str="";
  tmp=ch;
  
  while(tmp>=0){
    chStr=to_string(tmp);
    for(int i=0;i<chStr.length();i++){
      for(int j=0;j<v.size();j++){
        if(v[j]==chStr[i]-'0'){
          goto there;
        }
      }
    }
    if(ch-tmp+to_string(tmp).length()<min){
      str=to_string(tmp);
      min=ch-tmp+str.length();
    }
    break;
    there:
    tmp--;
  }

  tmp=ch;
  while(tmp<=1000000){
    chStr=to_string(tmp);
    for(int i=0;i<chStr.length();i++){
      for(int j=0;j<v.size();j++){
        if(v[j]==chStr[i]-'0'){
          goto there2;
        }
      }
    }
    if(tmp-ch+to_string(tmp).length()<min){
      str=to_string(tmp);
      min=tmp-ch+str.length();
    }
    break;
    there2:
    tmp++;
  }

  cout<<min;
  return 0;
}