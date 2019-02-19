#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

const ll INF = 1ll<<60;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];

    vector<ll> dp(n+1, INF);
    dp[0] = 0;
    for(int pi = 1; pi <= n; pi++){
        int i = pi - 1;
        int low = 1<<30, high = -1;
        for(int j = 0; j < min(m, pi); j++){
            low = min(low, a[i-j]);
            high = max(high, a[i-j]);
            dp[pi] = min(dp[pi], dp[pi-j-1] + k + (ll)(high-low)*(j+1));
        }
    }

    cout << dp[n] << endl;
    return 0;
}