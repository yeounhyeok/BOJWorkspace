#include<bits/stdc++.h>
using namespace std;
int ans, len, pos[200], cnt, g;
char key, dataa[1000010];

int main()
{
    int i;
    while(1){
        scanf("%c", &key);
        if (key == 10) break;
        pos[key] = ++cnt;
    }
    scanf("%s", &dataa);
    len = strlen(dataa);
    g = 1;
    for(i=len-1;i>=0;i--)
    {
        ans = (ans + g*pos[dataa[i]]) % 900528;
        g = g*cnt % 900528;
    }
    printf("%d", ans);
    return 0;
}