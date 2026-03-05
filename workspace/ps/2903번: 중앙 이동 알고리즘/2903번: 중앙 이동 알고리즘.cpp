#include <bits/stdc++.h>

using namespace std;

int main()
{  
    int n, ans=2;
    cin>>n;
    for(int i=1;i<=n;i++) ans+=(ans-1);
    ans = pow(ans, 2);
    cout<<ans;
    return 0;
}

