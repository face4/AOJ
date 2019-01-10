#include<iostream>
using namespace std;

const int INF = 1e9;

int main(){
    int v, e, s, t, d;
    cin >> v >> e;

    int dp[v][1<<v], dist[v][v];
    for(int i = 0; i < v; i++){
        for(int j = 0; j < 1<<v; j++){
            dp[i][j] = INF;
            if(j < v)   dist[i][j] = INF;
        }
    }

    // 巡回路なので始点を0に固定してしまっても問題ない
    dp[0][0] = 0;

    for(int i = 0; i < e; i++){
        cin >> s >> t >> d;
        dist[s][t] = d;
    }

    for(int s = 0; s < 1<<v; s++){
        for(int i = 0; i < v; i++){
            if(dp[i][s] == INF) continue;
            for(int j = 0; j < v; j++){
                if(i == j || dist[i][j] == INF || (s&(1<<j)))   continue;
                dp[j][s|(1<<j)] = min(dp[j][s|(1<<j)], dp[i][s]+dist[i][j]);
            }
        }
    }

    int ans = dp[0][(1<<v)-1];
    if(ans == INF)  ans = -1;
    cout << ans << endl;

    return 0;
}