#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> m1;
unordered_map<string, string> m2;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N, M;cin>>N>>M;
    string tmp;
    for(int i=1;i<=N;i++){
        cin>>tmp;
        m1.insert(make_pair(to_string(i), tmp));
        m2.insert(make_pair(tmp, to_string(i)));
        
    }

    for(int i=0;i<M;i++){
        cin>>tmp;
        if(tmp[0]>=49&&tmp[0]<=57){
            unordered_map<string, string>:: iterator iter = m1.find(tmp);
            cout<<iter->second<<'\n';
        }
        else{
            unordered_map<string, string>:: iterator iter = m2.find(tmp);
            cout<<iter->second<<'\n';
        }
    }
    return 0;
}