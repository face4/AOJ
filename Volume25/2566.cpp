#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int mod = 1e9+7;

int main(){
    string a, b, c;
    while(cin >> a, a != "0"){
        cin >> b >> c;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(c.begin(), c.end());
        int n = a.length();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                if(dp[i][j] == 0)   continue;
                for(int k = 0; k < 10; k++){
                    if(i == n-1 && k == 0)  continue;
                    if(a[i] != '?' && a[i]-'0' != k)    continue;
                    for(int l = 0; l < 10; l++){
                        if(i == n-1 && l == 0)  continue;
                        if(b[i] != '?' && b[i]-'0' != l)    continue;
                        if(c[i] == '?' || (j+k+l)%10 == c[i]-'0'){
                            dp[i+1][(j+k+l)/10] += dp[i][j];
                            dp[i+1][(j+k+l)/10] %= mod;
                        }
                    }
                }
            }
        }
        cout << dp[n][0] << endl;
    }
    return 0;
}