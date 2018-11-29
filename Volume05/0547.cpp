#include<iostream>
using namespace std;

const int mod = 100000;

int main(){
    int w, h;
    while(cin >> w >> h, w+h){
        int dp[101][101][4] = {};
        dp[0][0][1] = 1;
        dp[0][0][3] = 1;
        for(int j = 0; j < h; j++){
            for(int i = 0; i < w; i++){
                dp[i+1][j][0] += dp[i][j][1]+dp[i][j][0];
                dp[i+1][j][1] += dp[i][j][2];
                dp[i][j+1][2] += dp[i][j][3]+dp[i][j][2];
                dp[i][j+1][3] += dp[i][j][0];
                for(int u = 0; u < 4; u++){
                    dp[i][j+1][u] %= mod;
                    dp[i+1][j][u] %= mod;
                }
            }
        }

        int ans = 0;
        for(int u = 0; u < 4; u++){
            ans = (ans+dp[w-1][h-1][u])%mod;
        }
        cout << ans << endl;
    }
    return 0;
}