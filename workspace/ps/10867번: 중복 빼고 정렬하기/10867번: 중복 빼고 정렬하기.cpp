#import<bits/stdc++.h>
std::set<int> s;main(){int n,x;std::cin>>n;while(n--){std::cin>>x;s.insert(x);}for(auto i:s)std::cout<<i<<' ';}