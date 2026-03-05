#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.first==b.first) return a.second<b.second;
    else return a.first<b.first;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, a, b;
    vector <pair<int, int>> v;

    cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back(pair<int, int>(a, b));
	}
    
	sort(v.begin(), v.end(), cmp);

    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";;
    }
    return 0;
}


