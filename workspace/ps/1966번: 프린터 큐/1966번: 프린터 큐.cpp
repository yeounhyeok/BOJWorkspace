#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    if(a>b) return true;
    else return false;
}

int main(){
    int t, n, m;
    cin>>t;
    for(int i=0;i<t;i++){
        deque<pair<int, int>> v;
        vector<int> mx(105, -1);
        cin>>n>>m;

        for(int j=1;j<=n;j++){
            int tmp;cin>>tmp;
            if(mx[j]<tmp) mx[j] = tmp;
            v.push_back(make_pair(tmp, j)); //first : weigh, second : num
        }

        sort(mx.begin()+1, mx.begin()+n+1, cmp);
        int cnt=1;
        while(v.size()!=0){
            if((v.front().first)>=mx[n-v.size()+1]) {
                if(v.front().second-1==m){
                    cout<<cnt<<'\n';
                    break;
                }
                else {
                    v.pop_front();
                    cnt++;
                }
            }
            else{
                v.push_back(v.front());
                v.pop_front();
            }
        }
    }
    return 0;
}

