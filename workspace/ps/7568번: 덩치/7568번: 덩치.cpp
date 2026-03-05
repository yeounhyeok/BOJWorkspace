#include <iostream>
#include <vector>
using namespace std;

int n, w, h;

class man{
  public :
    int weight, height;
    explicit man(int& w, int& h) : weight(w), height(h) {}
};

vector<man> v;

int cmp(int& i, man& m){
    int cnt=1;
    for(int j=0;j<n;j++){
        if(i==j) continue;
        if(m.weight<v[j].weight && m.height<v[j].height) ++cnt;
    }
    return cnt;
}

int main(){
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>w>>h;
        v.push_back(man(w, h));
    }
    
    for(int i=0;i<n;i++) cout<<cmp(i, v[i])<<" ";
    
    
    return 0;
}
