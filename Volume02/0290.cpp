#include<iostream>
#include<vector>
using namespace std;

int f(int a, int b){
    return abs(a-b) * (abs(a-b)-30) * (abs(a-b)-30);
}

int main(){
    int m, w;
    while(cin >> m >> w, m+w){
        int bm[m], bw[w];
        for(int i = 0; i < m; i++)  cin >> bm[i];
        for(int i = 0; i < w; i++)  cin >> bw[i];
        vector<vector<int>> dp(m+1, vector<int>(1<<w, -1));
        dp[0][0] = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < 1<<w; j++){
                if(dp[i][j] < 0)    continue;
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                for(int k = 0; k < w; k++){
                    if((j>>k)&1)  continue;
                    dp[i+1][j|(1<<k)] = max(dp[i+1][j|(1<<k)], dp[i][j]+f(bm[i], bw[k]));
                }
            }
        }
        int ans = 0;
        for(int j = 0; j < 1<<w; j++)   ans = max(ans, dp[m][j]);
        cout << ans << endl;
    }
    return 0;
}