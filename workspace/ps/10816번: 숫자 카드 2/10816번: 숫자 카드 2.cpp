#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> myMap;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  int n, m, tmp;cin>>n;
  for(int i=0;i<n;i++){
    cin>>tmp;
    if(myMap.count(tmp)==0) myMap[tmp]=1;
    else myMap[tmp]++;
  }

  cin>>m;
  for(int i=0;i<m;i++){
    cin>>tmp;
    cout<<myMap[tmp]<<' ';
  }

  return 0;
}