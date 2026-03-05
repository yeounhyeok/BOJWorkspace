#import<bits/stdc++.h>
using namespace std;int n,m,i,a[10000];main(){cin>>n>>m;for(;i<n;i++)cin>>a[i];sort(a,a+n);cout<<a[n-m];}