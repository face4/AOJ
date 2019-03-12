#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

char mat[20][20];
int h, w;
vector<pair<int,int>> g;

vector<vector<int>> bfs(int si, int sj){
    vector<vector<int>> visit(h, vector<int>(w, 1<<30));
    queue<pair<int, pair<int,int>>> q;
    q.push({0, {si, sj}});
    while(!q.empty()){
        auto p = q.front(); q.pop();
        int c = p.first, i = p.second.first, j = p.second.second;
        if(visit[i][j] <= c)    continue;
        visit[i][j] = c;
        for(int k = 0; k < 4; k++){
            int ni = i+di[k], nj = j+dj[k];
            if(inRange(ni, 0, h) && inRange(nj, 0, w) && mat[ni][nj] != 'x' && c+1 < visit[ni][nj]){
                q.push({c+1, {ni, nj}});
            }
        }
    }
    return visit;
}

int main(){
    while(cin >> w >> h, w+h){
        int ri, rj;
        g.clear();
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
                if(mat[i][j] == 'o')    ri = i, rj = j;
                if(mat[i][j] == '*')    g.push_back({i, j});
            }
        }
        int gcnt = g.size();
        vector<vector<int>> dp(gcnt, vector<int>(1<<gcnt, 1<<30));
        auto p = bfs(ri, rj);
        bool valid = true;
        for(int i = 0; i < gcnt; i++){
            if(p[g[i].first][g[i].second] == 1<<30){
                valid = false;
                break;
            }
            dp[i][1<<i] = p[g[i].first][g[i].second];
        }

        if(!valid){
            cout << -1 << endl;
            continue;
        }

        vector<vector<int>> dist(gcnt, vector<int>(gcnt, 1<<30));
        for(int i = 0; i < gcnt; i++){
            auto p = bfs(g[i].first, g[i].second);
            for(int j = 0; j < gcnt; j++){
                dist[i][j] = p[g[j].first][g[j].second];
            }
        }

        for(int s = 0; s < 1<<gcnt; s++){
            for(int i = 0; i < gcnt; i++){
                if(((s>>i)&1)==0 || dp[i][s] == 1<<30) continue;
                for(int j = 0; j < gcnt; j++){
                    if((s>>j)&1) continue;
                    dp[j][s|(1<<j)] = min(dp[j][s|(1<<j)], dp[i][s] + dist[i][j]);
                }
            }
        }

        int ans = 1<<30;
        for(int i = 0; i < gcnt; i++)   ans = min(ans, dp[i][(1<<gcnt)-1]);
        cout << ans << endl;
    }
    return 0;
}