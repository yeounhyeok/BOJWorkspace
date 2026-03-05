#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;

void move(int from, int to){
    v.push_back(make_pair(from, to));
}

void hanoi(int n, int start, int to, int via){
    if(n==1) move(start, to);
    else{
        hanoi(n-1, start, via, to);
        move(start, to);
        hanoi(n-1, via, to, start);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;cin>>N;
    hanoi(N, 1, 3, 2);
    
    cout<<v.size()<<'\n';
    for(auto i:v) cout<<i.first<<' '<<i.second<<'\n';

    return 0;
}