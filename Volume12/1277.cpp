#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int main(){
    int n, t, l, b, x;
    while(cin >> n >> t >> l >> b, n+t+l+b){
        vector<int> mass(n+1, 0);
        while(l-- > 0){
            cin >> x;
            mass[x] = 1;
        }
        while(b-- > 0){
            cin >> x;
            mass[x] = 2;
        }
        vector<vector<double>> dp(2, vector<double>(n+1, 0));
        dp[0][0] = 1.0;
        for(int i = 0; i < t; i++){
            vector<vector<double>> ndp(2, vector<double>(n+1, 0));
            for(int j = 0; j < n; j++){
                for(int k = 1; k <= 6; k++){
                    int next = j+k;
                    if(next > n)    next = n - (next-n);
                    if(mass[next] == 1)         ndp[1][next] += dp[0][j]/6;
                    else if(mass[next] == 2)    ndp[0][0] += dp[0][j]/6;
                    else if(mass[next] == 0)    ndp[0][next] += dp[0][j]/6;
                }
            }
            for(int j = 0; j < n; j++)  ndp[0][j] += dp[1][j];
            ndp[0][n] += dp[0][n];
            dp = ndp;
        }
        cout << fixed << setprecision(12) << dp[0][n] << endl;
    }
    return 0;
}