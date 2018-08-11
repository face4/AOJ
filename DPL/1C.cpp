#include<iostream>
using namespace std;

int dp[101][10001] = {};
int v[101] = {}, w[101] = {};

int main(){
    int n, W;
    cin >> n >> W;

    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            if(w[i] > j)    
                dp[i][j] = dp[i-1][j];
            else            
                dp[i][j] = max(dp[i-1][j], max(dp[i-1][j-w[i]]+v[i], dp[i][j-w[i]]+v[i]));
        }
    }

    cout << dp[n][W] << endl;

    return 0;
}