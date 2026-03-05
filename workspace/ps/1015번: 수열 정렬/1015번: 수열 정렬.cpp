#include <bits/stdc++.h>
using namespace std;
int p[55], tmp;
tuple<int, int, int> a[55];

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
    if(get<1>(a) < get<1>(b)) return true;
    else return false;
}

int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        a[i] = make_tuple(tmp, i, -1);
    }
    for(int i=0;i<n;i++){
        int idx=i;
        for(;;){
            if(idx>0 && get<0>(a[idx])<get<0>(a[idx-1])){
                swap(a[idx], a[idx-1]);
                idx--;
                continue;
            }
            break;
        }
    }

    for(int i=0;i<n;i++){
        get<2>(a[i]) = i;
    }

    sort(a, a+n, cmp);

    for(int i=0;i<n;i++){
        cout<<get<2>(a[i])<<' ';
    }

    return 0;
}