#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node{
    ll size=0, num;
    node *lt=nullptr, *rt=nullptr;
    node(ll n) : num(n) {};
};

vector<node*> v;

void deleteNode(node* x){
    node *tmpL = x->lt, *tmpR = x->rt;
    delete x;
    tmpL->rt = tmpR;
    tmpR->lt = tmpL;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n, last;cin>>n;
    last = n;

    for(ll i=0;i<=n+1;i++) {
        node* tmp = new node(i);
        v.push_back(tmp);
    }
    for(ll i=1;i<=n;i++) {
        v[i]->lt = v[i-1];
        v[i]->rt = v[i+1];
    }
    for(ll i=1;i<=n;i++) cin>>v[i]->size;
    
    node* cur = v[1];
    while(last>1){
        while(cur->lt->num!=0) cur = cur->lt;
        while(last>1){
            bool lflag = cur->lt->size <= cur->size, rflag = cur->rt->size <= cur->size;
            if(cur->lt->num!=0 && lflag){
                cur->size+=cur->lt->size;
                deleteNode(cur->lt);
                last--;
            }
            if(cur->rt->num!=n+1 && rflag){
                cur->size+=cur->rt->size;
                deleteNode(cur->rt);
                last--;
            }
            if(cur->rt->num!=n+1) cur=cur->rt;
            else break;
        }
    }
    cout<<cur->size<<'\n'<<cur->num;
    return 0;
}