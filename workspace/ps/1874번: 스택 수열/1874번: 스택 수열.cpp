#include <bits/stdc++.h>

using namespace std;
stack<int> s;
string str;
int arr[100001];
bool init[100001], isFirst=true;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n, tmp, pos=1;cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        if(pos>n){
            cout<<"NO";
            return 0;
        }
        while(pos!=arr[i]){
            s.push(pos);
            init[pos]=true;
            str+="+";
            if(!init[pos+1]) pos++;
            else for(;init[pos];pos++);
            if(pos>n){
                cout<<"NO";
                return 0;
            }
        }
        str+="+-";
        if(!init[pos+1]) pos++;
        else for(;init[pos];pos++);
        while(s.size()!=0&&s.top()==arr[i+1]){
            init[s.top()]=false;
            s.pop();
            str+="-";
            if(i+1<n) i++;
            else break;
        }
    }
    for(int i=0;i<str.length();i++) cout<<str[i]<<'\n';
    return 0;
}

