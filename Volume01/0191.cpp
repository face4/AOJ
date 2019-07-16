#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        double g[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> g[i][j];
            }
        }
        double dp[101][100] = {};
        for(int i = 0; i < n; i++)  dp[0][i] = 1.0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    dp[i+1][k] = max(dp[i+1][k], dp[i][j]*g[j][k]);
                }
            }
        }
        double ans = 0;
        for(int i = 0; i < n; i++)  ans = max(ans, dp[m-1][i]);
        ans = round(ans*100);
        printf("%.2f\n", ans/100);
    }
    return 0;
}