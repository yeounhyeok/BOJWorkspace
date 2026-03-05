#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  long long c, n0, a0, a1;
  cin>>a1>>a0>>c>>n0;
  if(a1*n0+a0<=c*n0&&a1<=c) cout<<1;
  else cout<<0;

  return 0;
}