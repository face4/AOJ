#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n;
    while(cin >> n, n){
        vector<vector<int>> dp(n+1, vector<int>(4, 1<<30));
        dp[0][0] = 0;
        int befp = 0, beft = 0, ans = -1;
        for(int i = 0; i < n; i++){
            int p, t;
            cin >> p >> t;
            bool ok = false;
            for(int j = 0; j < 4; j++){
                if(dp[i][j] == 1<<30) continue;
                if(j != 0){
                    if(befp*(j+1) + p*(0+1) <= t-beft){
                        ok = true;
                        dp[i+1][1] = min(dp[i+1][1], dp[i][j]+befp+p);
                    }
                }
                if(j != 3){
                    if(abs(befp-p)*(j+1) <= t-beft){
                        ok = true;
                        dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+abs(befp-p));
                    }
                }
            }
            if(!ok && ans == -1){
                ans = i+1;
            }
            befp = p, beft = t;
        }
        if(ans != -1){
            cout << "NG " << ans << endl;
            continue;
        }
        ans = 1<<30;
        for(int j = 1; j < 4; j++){
            ans = min(ans, dp[n][j]);
        }
        cout << "OK " << ans+befp << endl;
    }
    return 0;
}
