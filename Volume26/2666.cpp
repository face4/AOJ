#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int,int> pii;
int dp[101][101][1<<4];

int main(){
    memset(dp, 0x3f, sizeof(dp));
    int n, m, e, s, t, r;
    cin >> n >> m >> e >> s >> t >> r;
    vector<pii> v[n];
    while(m--){
        int a, b;
        cin >> a >> b;
        v[a].push_back({b,-1});
        v[b].push_back({a,-1});
    }
    vector<int> event(n, -1);
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        event[c] = i;
        v[a].push_back({b, i});
        v[b].push_back({a, i});
    }
    int initStat = 0;
    if(event[s] != -1)  initStat += 1<<event[s];
    dp[s][0][initStat] = 0;
    queue<pair<pii,int>> q;
    q.push({{s,0},initStat});
    while(!q.empty()){
        auto p = q.front(); q.pop();
        int pos = p.first.first, dist = p.first.second, stat = p.second;
        // play ocarina
        if(dp[s][0][stat] > dp[pos][dist][stat]+1){
            dp[s][0][stat] = dp[pos][dist][stat]+1;
            q.push({{s,0},stat});
        }
        if(dist == r)   continue;
        // move
        for(pii next : v[pos]){
            int npos = next.first;
            int roadStat = next.second;
            int nstat = stat;
            if(roadStat != -1 && (stat>>roadStat&1) == 0) continue;
            if(event[npos] != -1)    nstat |= 1<<event[npos];
            if(dp[npos][dist+1][nstat] > dp[pos][dist][stat]+1){
                dp[npos][dist+1][nstat] = dp[pos][dist][stat]+1;
                q.push({{npos,dist+1},nstat});
            }
        }
    }
    int ans = 1<<30;
    for(int i = 0; i <= r; i++){
        for(int j = 0; j < 1<<e; j++){
            ans = min(ans, dp[t][i][j]);
        }
    }
    cout << (ans > 1e9 ? -1 : ans) << endl;
    return 0;
}