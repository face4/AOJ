#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// dp[i][j] := ジョブiまで考慮した際にjジョブやり切った時の最短時間

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n);
    for(int i = 0; i < n; i++){
        cin >> vp[i].second >> vp[i].first;
    }
    sort(vp.begin(), vp.end());
    const int INF = 1<<29;
    int dp[n+1][n+1];
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            int ctim = dp[i][j];
            int ntim = ctim+vp[i].second;
            if(ntim <= vp[i].first) dp[i+1][j+1] = min(dp[i+1][j+1], ntim);
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        }
    }
    for(int i = n; i >= 0; i--){
        if(dp[n][i] == INF) continue;
        cout << i << endl;
        return 0;
    }
}