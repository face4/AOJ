#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int INF = 1<<30;
int c, n, m, s, d, a, b, f;
int path[101][101];
int dp[101][11] = {};

void solve(){
    // { cost, {source, ticket} }
    priority_queue<pair<int, pair<int,int>>> pq;
    pq.push({0, {s, c}});
    dp[s][c] = 0;

    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        int cost = -p.first;
        int source = p.second.first;
        int ticket = p.second.second;

        for(int dst = 0; dst < n; dst++){
            if(path[source][dst] == 0)  continue;

            if(dp[dst][ticket] > cost + path[source][dst]){
                dp[dst][ticket] = cost + path[source][dst];
                pq.push({-dp[dst][ticket], {dst, ticket}});
            }

            if(ticket > 0 && dp[dst][ticket-1] > cost + path[source][dst]/2){
                dp[dst][ticket-1] = cost + path[source][dst]/2;
                pq.push({-dp[dst][ticket-1], {dst, ticket-1}});
            }
        }
    }
}

int main(){
    while(cin >> c >> n >> m >> s >> d){
        if(c + n + m + s + d == 0)  break;

        s--; d--;
        // initialize
        memset(path, 0, sizeof(path));
        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 11; j++){
                dp[i][j] = INF;
            }
        }

        for(int i = 0; i < m; i++){
            cin >> a >> b >> f;
            a--; b--;
            path[a][b] = path[b][a] = f;
        }

        solve();

        int ans = INF;
        for(int ticket = 0; ticket <= c; ticket++)  ans = min(ans, dp[d][ticket]);
        cout << ans << endl;
    }
    return 0;
}