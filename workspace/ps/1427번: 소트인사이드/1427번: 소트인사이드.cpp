#include <bits/stdc++.h>

using namespace std;

char arr[11];

int main(){
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  cin>>arr;
  int i;
  for(i=0;arr[i]!='\0';i++);
  sort(arr, arr+i, greater<>());
  for(i=0;arr[i]!='\0';i++) cout<<arr[i];
  
  return 0;
}