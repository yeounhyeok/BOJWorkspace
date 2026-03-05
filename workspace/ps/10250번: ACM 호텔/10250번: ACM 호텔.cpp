#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> ans;
int T, H, W, N, tmp;
bool flag;

int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>H>>W>>N;
        flag = false;
        tmp = 1;
        for(int w=1;w<=W;w++){
            for(int h=1;h<=H;h++){
                if(tmp==N){
                    ans.push_back(make_pair(h, w));
                    flag=true;
                    break;
                }
                tmp++;
            }
            if(flag) break;
        }
        
    }
    for(int i=0;i<T;i++) printf("%d%02d\n", ans[i].first, ans[i].second);
    return 0;
}