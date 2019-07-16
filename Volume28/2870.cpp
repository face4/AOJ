#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main(){
    bool np[1000001] = {};
    np[0] = np[1] = true;
    for(int i = 2; i < 1000001; i++){
        if(np[i])   continue;
        for(int j = i+i; j < 1000001; j += i)   np[j] = true;
    }

    int n;
    cin >> n;
    vector<int> q(n);
    for(int i = 0; i < n; i++)  cin >> q[i];

    if(np[q[0]]){
        cout << 0 << endl;
        return 0;
    }
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    vector<vector<ll>> dp(2, vector<ll>(n,0));
    dp[1][0] = 1;
    dp[0][1] = 1;
    if(!np[q[1]] && q[1] > q[0])    dp[1][1] = 1;
    for(int i = 2; i < n; i++){
        // 指数の肩ver
        if(!np[q[i-1]]) dp[0][i] = (dp[0][i] + dp[1][i-1]) % mod;
        // 素数ver
        if(!np[q[i]]){
            if(!np[q[i-1]] && q[i] > q[i-1]) dp[1][i] = (dp[1][i] + dp[1][i-1]) % mod;
            if(!np[q[i-2]] && q[i] > q[i-2]) dp[1][i] = (dp[1][i] + dp[1][i-2]) % mod;
        }
    }

    cout << (dp[0][n-1]+dp[1][n-1])%mod << endl;
    return 0;
}