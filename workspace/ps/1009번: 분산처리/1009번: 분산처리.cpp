/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1009                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: yeopeter1031 <boj.kr/u/yeopeter1031>        +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1009                           #+#        #+#      #+#    */
/*   Solved: 2026/02/14 05:38:04 by yeopeter1031  ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
/*
9 - 1 - 9 - 1 - 9 - 1 - 9 - 1 - 9 - 1
7 - 9 - 3 - 
13 - 9
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, a, b, result;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        result = a%10;
        if( a==1) cout<<1<<'\n';
        else if(a%10==0) cout<<10<<'\n';
        else{
            while(--b) result = (result * a)%10;
            cout<<result<<'\n';
        }
    }
    return 0;
}