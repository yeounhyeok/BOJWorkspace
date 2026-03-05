#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;int arr[55];cin>>n;

  for(int i=0;i<n;i++) cin>>arr[i];
  sort(arr, arr+n);
  

  if(n%2==0) cout<<arr[0]*arr[n-1];
  else cout<<arr[((n+1)/2)-1]*arr[((n+1)/2)-1];

  return 0;
}
