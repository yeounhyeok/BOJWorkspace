#include <bits/stdc++.h>

using namespace std;

deque<int> q;

int main(){
    int n, tmp;cin>>n;
    for(int i=1;i<=n;i++) q.push_back(i);
    while(q.size()>1){
        q.pop_front();
        if(q.size()<=1) break;
        q.push_back(q.front());
        q.pop_front();
    }
    cout<<q.front();
    return 0;
}



