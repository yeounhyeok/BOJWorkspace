#include <bits/stdc++.h>
using namespace std;

vector<int> v, gap;
int n, k, tmp;

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n-1;i++){
        gap.push_back(v[i+1]-v[i]);
    }
    sort(gap.begin(), gap.end(), greater<>());
    int s = accumulate(gap.begin(), gap.end(), 0);
    for(int i=0;i<k-1&&i<n-1;i++) s-=gap[i];
    cout<<s;
    return 0;
}