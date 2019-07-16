#include<iostream>
#include<vector>
using namespace std;

const int mod = 100000;

int main(){
    int n, m, s;
    while(cin >> n >> m >> s, n+m+s){
        vector<vector<int>> dp(n*n+1, vector<int>(s+1,0));
        dp[0][0] = 1;
        for(int i = 1; i <= m; i++){  // 今採用することを検討している数
            vector<vector<int>> dp2 = dp;
            for(int j = n*n; j >= 1; j--){ // iを含めて、選択した要素数
                for(int k = s; k >= 0; k--){ // 今iを採用した時の選択した要素数の総和
                    if(k >= i)  dp2[j][k] = (dp2[j][k] + dp[j-1][k-i])%mod; // iを使う
                }
            }
            dp = dp2;
        }
        cout << dp[n*n][s] << endl;
    }
    return 0;
}