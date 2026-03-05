#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<ll> v;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  int tmp, n;cin>>n;
  for(int i=0;i<n;i++){
    cin>>tmp;
    v.push_back(tmp);
  }
  vector<ll> v_sorted(v);
  sort(v_sorted.begin(), v_sorted.end());


  vector<ll> subv;
  for(int i=0;i<n;i++){
    if(lower_bound(subv.begin(), subv.end(), v_sorted[i])-subv.begin()!=subv.size()-1) subv.push_back(v_sorted[i]);
  }


  map<ll, ll> m;
  for(int i=0;i<subv.size();i++) m[subv[i]]=i;
  
  for(int i=0;i<n;i++){
    cout<<m[v[i]]<<' ';
  }

  return 0;
}