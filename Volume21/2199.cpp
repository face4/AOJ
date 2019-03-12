#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        vector<vector<int>> dp(256, vector<int>(n+1, 1<<30));
        dp[128][0] = 0;
        vector<int> c(m);
        for(int i = 0; i < m; i++)  cin >> c[i];
        for(int i = 0; i < n; i++){
            int x;  cin >> x;
            for(int j = 0; j < 256; j++){
                for(int k = 0; k < m; k++){
                    int next = j + c[k];
                    if(next < 0)    next = 0;
                    if(next > 255)  next = 255;
                    dp[next][i+1] = min(dp[next][i+1], dp[j][i]+(next-x)*(next-x));
                }
            }
        }
        int ans = 1<<30;
        for(int j = 0; j < 256; j++)    ans = min(ans, dp[j][n]);
        cout << ans << endl;
    }
    return 0;
}