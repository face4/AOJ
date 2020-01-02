#include<iostream>
using namespace std;

int dp[2][2001][2001] = {};

int main(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i] == 'I') dp[1][i+1][j] = 1;
            if(t[j] == 'I') dp[1][i][j+1] = 1;
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k < 2; k++){
                if(dp[k][i][j] == 0)    continue;
                if(i < n && s[i] == "IO"[k]) dp[1-k][i+1][j] = max(dp[1-k][i+1][j], dp[k][i][j]+1);
                if(j < m && t[j] == "IO"[k]) dp[1-k][i][j+1] = max(dp[1-k][i][j+1], dp[k][i][j]+1);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ans = max(ans, dp[1][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}