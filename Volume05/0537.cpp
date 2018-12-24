#include<iostream>
#include<cstring>
using namespace std;

const int mod = 1e5;
int dp[50][3001] = {};

int main(){
    int n, m, s;
    while(cin >> n >> m >> s, n+m+s){
        n *= n;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        // i...今部分和の構成員として採用しようとしている数
        for(int i = 1; i <= m; i++){
            //　j...iを含めた項数
            for(int j = n; j > 0; j--){
                // k...iを含める前のj-1項の和
                for(int k = 0; k <= s-i; k++){
                    dp[j][k+i] += dp[j-1][k];
                    dp[j][k+i] %= mod;
                }
            }
        }

        cout << dp[n][s] << endl;
    }
    return 0;
}