#include <bits/stdc++.h>

using namespace std;
vector<pair<string, int>> str;
string substr;
int subint;

bool cmp(pair<string, int>& front, pair<string, int>& back)
{
	if (front.second!=back.second) return front.second < back.second;
	else if (front.second == back.second)	return front.first < back.first;
}


int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>substr;
        subint=substr.length();
        str.push_back(pair<string, int> (substr, subint));
    }
    sort(str.begin(), str.end(), cmp);
    for(int i=0;i<n;i++){
        if(str[i].first==str[i+1].first) continue;
        cout<<str[i].first<<'\n';
    }
    return 0;
}
