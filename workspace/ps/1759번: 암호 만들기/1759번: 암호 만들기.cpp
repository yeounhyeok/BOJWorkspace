#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
using namespace std;

int l, c;
char arr[15];

bool chk(string s){
    int flag=-1, cnt=0;
    for(auto x:s) {
        if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u') {
            flag++;
            break;
        }
    }
    for(auto x:s){
        if(!(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')) cnt++;
        if(cnt==2){
            flag++;
            if(flag>0) return 1;
            break;
        }
    }
    return 0;
}

void dfs(int idx, string& s){
    s+=arr[idx];
    if(s.size()==l && chk(s))cout<<s<<'\n';
    else{
        rep(i, idx, c-1) {
            dfs(i+1, s);
            s.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>l>>c;
    rep(i, 0, c) cin>>arr[i];
    sort(arr, arr+c);
    
    rep(i, 0, c) {
        string s="";
        dfs(i, s);
    }
    return 0;
}