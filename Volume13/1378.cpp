#include<iostream>
using namespace std;

typedef long long ll;

// height, color
ll dp[111][2] = {};

int main(){
    int l, k;
    cin >> l >> k;

    dp[k][1] = 1;
    dp[1][1] = 1;

    for(int i = 1; i <= l; i++){
        dp[i+1][0] += dp[i][1];
        dp[i+1][1] += dp[i][0];
        dp[i+k][1] += dp[i][0];
    }

    ll ans = 0;
    for(int i = 1; i <= l; i++){
        ans += dp[i][1];
    }

    cout << ans << endl;
    
    return 0;
}