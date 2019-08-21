#include<iostream>
#include<vector>
using namespace std;
const int mod = 1e9 + 7;

int main(){
    int n, l;
    cin >> n >> l;
    vector<int> x(n), a(n);
    for(int i = 0; i < n; i++)  cin >> x[n-1-i];
    for(int i = 0; i < n; i++)  cin >> a[n-1-i];
    vector<vector<int>> dp(2, vector<int>(l+1, 0));
    for(int j = x[0]; j < l; j += a[0]){
        dp[0][j] = 1;
        if(a[0] == 0)   break;
    }
    for(int j = l-1; j >= 0; j--)  dp[0][j] = (dp[0][j] + dp[0][j+1])%mod;
    for(int i = 1; i < n; i++){
        fill(dp[i%2].begin(), dp[i%2].end(), 0);
        for(int j = x[i]; j < l; j += a[i]){
            dp[i%2][j] = dp[(i+1)%2][j+1];
            if(a[i] == 0)   break;
        } 
        for(int j = l-1; j >= 0; j--)   dp[i%2][j] = (dp[i%2][j] + dp[i%2][j+1])%mod;
    }
    cout << dp[(n+1)%2][0] << endl;
    return 0;
}