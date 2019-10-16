#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m;
    while(cin >> m, m){
        vector<int> t(m);
        for(int i = 0; i < m; i++)  cin >> t[i];
        vector<int> d(100, 24);
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            d[a-1] = min(d[a-1], b);
        }
        vector<vector<int>> dp(100, vector<int>(m, 1<<30));
        dp[0][0] = 0;
        for(int i = 0; i+1 < 100; i++){
            for(int j = 0; j < m; j++){
                if(dp[i][j] == 1<<30)   continue;
                dp[i+1][0] = min(dp[i+1][0], dp[i][j]+1);
                if(t[(j+1)%m] <= d[i+1])   dp[i+1][(j+1)%m] = min(dp[i+1][(j+1)%m], dp[i][j]);
            }
        }
        int ans = 1<<30;
        for(int j = 0; j < m; j++)  ans = min(ans, dp[99][j]);
        cout << ans << endl;
    }
    return 0;
}