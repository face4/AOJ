#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, d, x;
    cin >> n >> d >> x;
    int p[d][n];
    for(int i = 0; i < d; i++){
        for(int j = 0; j < n; j++){
            cin >> p[i][j];
        }
    }
    for(int i = 0; i < d-1; i++){
        vector<int> dp(x+1, 0);
        for(int j = 0; j < n; j++){
            int wei = p[i][j], val = p[i+1][j];
            if(wei > x) continue;
            dp[wei] = max(dp[wei], val);
            for(int k = wei+1; k <= x; k++){
                if(dp[k-wei] == 0)  continue;
                dp[k] = max(dp[k], dp[k-wei]+val);
            }
        }
        int nx = 0;
        for(int k = 0; k <= x; k++){
            nx = max(nx, dp[k] + x-k);
        }
        x = nx;
    }
    cout << x << endl;
    return 0;
}