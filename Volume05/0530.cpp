#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int dp[150][11][80];
const int INF = 1<<30;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        memset(dp, 0, sizeof(dp));
        vector<pair<int,int>> v[n];
        for(int i = 0; i < n; i++){
            int k;  cin >> k;
            while(k-- > 0){
                int x, d; cin >> x >> d;
                v[i].push_back({x, d});
                for(int j = 0; j <= m; j++){
                    dp[i][k][j] = INF;
                }
            }
        }
        
        for(int j = 0; j < v[0].size(); j++){
            dp[0][j][m] = 0;
        }
        for(int j = 0; j < v[1].size(); j++){
            if(m)   dp[1][j][m-1] = 0;
        }
        
        int ans = INF;
        for(int i = 0; i < n-1; i++){
            for(int from = 0; from < v[i].size(); from++){
                for(int mm = m; mm >= 0; mm--){
                    if(dp[i][from][mm] == INF)   continue;
                    for(int to = 0; to < v[i+1].size(); to++){
                        int cost = abs(v[i][from].first-v[i+1][to].first)*(v[i][from].second+v[i+1][to].second);
                        dp[i+1][to][mm] = min(dp[i+1][to][mm], dp[i][from][mm]+cost);
                        if(i+1 == n-1)  ans = min(ans, dp[i+1][to][mm]);
                    }
                    if(mm == 0)  continue;
                    if(i == n-2){
                        ans = min(ans, dp[i][from][mm]);
                        continue;
                    }
                    for(int to = 0; to < v[i+2].size(); to++){
                        int cost = abs(v[i][from].first-v[i+2][to].first)*(v[i][from].second+v[i+2][to].second);
                        dp[i+2][to][mm-1] = min(dp[i+2][to][mm-1], dp[i][from][mm]+cost);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}