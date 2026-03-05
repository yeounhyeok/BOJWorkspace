#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int timearr[10000001];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, a, b, start, idx=0, leftTime;
    vector <pair<int, int>> v;

    cin>>n;
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back(pair<int, int>(a, b));
	}
     
    for(int i=0;i<v.size();i++){
        leftTime = v[i].first;
        for(int j=v[i].second-1;leftTime!=0;j--){
            if(!timearr[j]){
                timearr[j]++;
                leftTime--;
            }
            if(j<0){
                cout<<-1;
                return 0;
            }
        }
    }

    while(1){
        if(timearr[idx]) break;
        idx++;
    }
    
    cout<<idx;
    
    return 0;
}


