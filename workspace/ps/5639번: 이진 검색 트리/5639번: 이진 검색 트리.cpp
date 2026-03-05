#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void bi(int start, int end){
    if (start >= end) {
		return;
	}
	if (start == end - 1) {
		cout << v[start] << '\n';
		return;
	}
	int idx = start + 1;
	while (idx<end) {
		if (v[start]<v[idx]) {
			break;
		}
		idx++;
	}
	
	bi(start+1, idx);
	bi(idx, end);
	cout << v[start] << '\n';
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tmp;
    while(!cin.eof()){
        cin>>tmp;
        v.push_back(tmp);
    }
    bi(0, v.size()-1);

    return 0;
}