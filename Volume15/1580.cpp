// ふがしは初期300+交換+300で最大600本持つ可能性があり、
// これを素直に実装すれば301(うまか[0,300])*901(ふがし[-300,600])
// ところが、sum(c_i)が300以下なので、ふがしを301本以上持つのは無意味
// よってふがしを301以上持つ状態は無いものとして
// 301(うまか[0,300])*601(ふがし[-300,300])で実装してよい
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> dp(301, vector<int>(601, -10000));

int main(){
    int n, x, y;
    scanf("%d", &n);
    scanf("%d %d", &x, &y);
    dp[x][300+y] = 0;
    for(int i = 0; i < n; i++){
        vector<vector<int>> ndp = dp;
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for(int j = 0; j <= 300; j++){
            for(int k = 0; k <= 600; k++){
                if(dp[j][k] < 0)    continue;
                if(j >= a && k+b <= 600)  ndp[j-a][k+b] = max(ndp[j-a][k+b], dp[j][k]);
                if(k >= c)  ndp[j][k-c] = max(ndp[j][k-c], dp[j][k]+d);
            }
        }
        dp = ndp;
    }
    int ans = 0;
    for(int i = 0; i <= 300; i++){
        for(int j = 300; j <= 600; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}