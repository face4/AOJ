#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

int room[2][500][500];
bool visit[2][500][500];

int main(){
    int r;
    while(cin >> r, r){
        int w[2], h[2], x[2], y[2];
        memset(room, 0, sizeof(room));
        memset(visit, 0, sizeof(visit));
        for(int s = 0; s < 2; s++){
            cin >> w[s] >> h[s] >> x[s] >> y[s];
            x[s]--, y[s]--;
            for(int i = 0; i < h[s]; i++){
                for(int j = 0; j < w[s]; j++){
                    cin >> room[s][i][j];
                }
            }
        }
        map<int,int> m[2], n[2];
        for(int s = 0; s < 2; s++){
            int tmplevel = 0;
            priority_queue<pair<int,pair<int,int>>> pq;
            pq.push({-room[s][y[s]][x[s]], {y[s], x[s]}});
            visit[s][y[s]][x[s]] = true;
            int cnt = 0;
            while(!pq.empty()){
                auto p = pq.top();  pq.pop();
                int val = -p.first, i = p.second.first, j = p.second.second;
                tmplevel = max(tmplevel, val);
                m[s][tmplevel] = ++cnt;
                for(int k = 0; k < 4; k++){
                    int ni = i + di[k], nj = j + dj[k];
                    if(inRange(ni, 0, h[s]) && inRange(nj, 0, w[s]) && !visit[s][ni][nj]){
                        visit[s][ni][nj] = true;
                        pq.push({-room[s][ni][nj], {ni, nj}});
                    }
                }
            }
            for(auto p : m[s]){
                n[s][p.second] = p.first;
            }
            n[s][0] = 0;   // sentinel
        }
        int ans = 1<<30;
        for(auto p : n[0]){
            int residual = r-p.first;
            auto it = n[1].lower_bound(residual);
            if(it != n[1].end()){
                ans = min(ans, p.second + n[1].lower_bound(residual)->second);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
