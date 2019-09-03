#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

const int mod = 1000000007;

int main(){
    int n, w;
    cin >> n >> w;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(v.rbegin(), v.rend());
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= w; j++){
            dp[i+1][j] = dp[i][j];
            if(j >= v[i]){
                dp[i+1][j] += dp[i][j-v[i]];
                dp[i+1][j] %= mod;
            }
        }
    }
    int ans = 0, weight = 0;
    if(accumulate(v.begin(), v.end(), 0) <= w)  ans++;
    for(int i = n-1; i >= 0; i--){
        // v[i] を使わず、 v[i+1] ... v[n-1]を全部使う.その和はweight
        if(weight > w)  continue;
        for(int j = max(0, w-weight-v[i]+1); j <= w-weight; j++)    ans += dp[i][j], ans %= mod;
        weight += v[i];
    }
    cout << ans << endl;
    return 0;
}
