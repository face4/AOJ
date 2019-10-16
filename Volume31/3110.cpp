#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

int dp[200001][2] = {};
int dp2[200001][2] = {};

int main(){
    string s, t;
    cin >> s >> t;
    int n = s.length();
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            if(dp[i][j] == 0)   continue;
            for(int k = 0; k < 10; k++){
                if(j == 0 && k > s[i]-'0')  break;
                if(t[i] != '?' && t[i]-'0' != k)    continue;
                int nj = j | (s[i]-'0' > k);
                dp[i+1][nj] += dp[i][j];
                dp[i+1][nj] %= mod;
                dp2[i+1][nj] += ((ll)dp2[i][j]*10 + (ll)(dp[i][j])*k)%mod;
                dp2[i+1][nj] %= mod;
            }
        }
    }
    cout << (dp2[n][0]+dp2[n][1])%mod << endl;
    return 0;
}
