#include <bits/stdc++.h>

using namespace std;

bool arr[7000][7000];

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  for(int i=0;i<=2;i++){
    arr[0][i]=true;
    arr[i][0]=true;
  }
  arr[1][2]=true;arr[2][1]=true;arr[2][2]=true;

  int N;cin>>N;
  for(int i=9;i<=N;i*=3){

    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
        if(j==1&&k==1) continue;
        
        for(int x=0;x<i/3;x++){
          for(int y=0;y<i/3;y++){
            if(arr[x][y]) arr[x+j*i/3][y+k*i/3]=true;
          }
        }

      } 
    }
    
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(arr[i][j]) cout<<"*";
      else cout<<" ";
    }
    cout<<'\n';
  }
  
  return 0;
}