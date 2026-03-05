#include <stdio.h>

int arr[10001];

int main() {
  int a, n, cnt=0;
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    scanf("%d", &a);
    arr[a]++;
  }
  for(int i=1;i<10001;i++){
    if(arr[i]!=0){
      for(int j=1;j<=arr[i];j++) printf("%d\n", i);
    }
  }
}