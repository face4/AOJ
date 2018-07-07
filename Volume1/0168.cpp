// dp[n]/365/10 + 1でいけるらしい.何故だかわからない
// 365や10の倍数になるような段数が存在しない(だろう)という
// 適当な仮定からくる嘘解法ではないか？？
// 7300とかダメな気がする.まあdpに出てこないので良い.

#include<iostream>
using namespace std;

int main(){
    int dp[31] = {1, 1, 2};
    for(int i = 3; i <= 30; i++)    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

    while(1){
        int n;
        cin >> n;
        if(n == 0)  break;
        int ans = (((dp[n]+9) / 10) + 364) / 365;
        cout << ans << endl;
    }

    return 0;
}