#include <bits/stdc++.h>

using namespace std;

int xarr[100001], yarr[100001];

int main() {
  int n, w0, w1, h0, h1;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>xarr[i]>>yarr[i];
  }
  sort(xarr, xarr+n);
  sort(yarr, yarr+n);

  w0=xarr[0]; w1=xarr[n-1];
  h0=yarr[0]; h1=yarr[n-1];

  cout<<(w1-w0)*(h1-h0);
  
  return 0;
}