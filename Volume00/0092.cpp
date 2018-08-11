#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        char mat[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        
        for(int i = 0; i < n; i++){
            if(mat[0][i] == '.')    dp[0][i] = 1;
            if(mat[i][0] == '.')    dp[i][0] = 1;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < n; j++){
                if(mat[i][j] == '.')
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dp[i][j]);
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}
