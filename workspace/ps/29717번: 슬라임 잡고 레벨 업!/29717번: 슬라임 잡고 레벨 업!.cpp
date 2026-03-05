#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;cin>>n;
  long double tmp;
  for(int i=0;i<n;i++){
    cin>>tmp;
    cout<<(int)(1+sqrt(1+2*tmp*(tmp+1)))/2<<'\n';
  }
  
  return 0;
}