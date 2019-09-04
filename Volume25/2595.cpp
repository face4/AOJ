#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

int main(){
    int n, x;
    ll d;
    while(cin >> n >> d >> x, n){
        ll ans = 0, tmp = 1;
        vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
        for(int j = 0; j <= n; j++) dp[0][j] = 1;
        for(int i = 1; i <= n; i++){
            if(i > d)   break;
            tmp *= (d-i+1)%mod;
            tmp %= mod;
            tmp *= modpow(i, mod-2, mod);
            tmp %= mod;
            for(int j = 1; j <= n; j++){
                dp[i][j] = (dp[i-1][j-1] - (j-x < 0 ? 0 : dp[i-1][j-x]) + mod)%mod;
            }

            if(dp[i][n]){
                ans += tmp * dp[i][n];
                ans %= mod;
            }
            for(int j = 1; j <= n; j++){
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
        cout << ans << endl;
    }
    return 0;
}