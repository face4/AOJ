#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int d, n;
    while(cin >> d >> n, d+n){
        vector<int> a(n), e(n), r(n);
        for(int i = 0; i < n; i++)  cin >> a[i] >> e[i] >> r[i];
        vector<vector<int>> dp(d+1, vector<int>(101, 1<<30));
        dp[0][0] = 0;
        for(int du = 0; du <= d; du++){
            for(int ex = 0; ex < 101; ex++){
                for(int k = 0; k < n; k++){
                    if(dp[du][ex] == 1<<30 || r[k] > ex)    continue;
                    dp[min(du+a[k],d)][min(100,ex+e[k])] = 
                        min(dp[min(du+a[k],d)][min(100,ex+e[k])], dp[du][ex]+1);
                }
            }
        }
        int ans = 1<<30;
        for(int i = 0; i < 101; i++)    ans = min(ans, dp[d][i]);
        if(ans == 1<<30)    cout << "NA" << endl;
        else                cout << ans << endl;
    }
    return 0;
}