#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<cfloat>
using namespace std;

double dp[30][30][100];

void init(){
    for(int i = 0; i < 30; i++) for(int j = 0; j < 30; j++)
    for(int k = 0; k < 100; k++)    dp[i][j][k] = DBL_MAX;
}

struct data{
    int to, d, u;
};

#define F first
#define S second

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        init();
        int s, g;   cin >> s >> g;
        s--, g--;
        vector<data> v[n];
        while(m-- > 0){
            int x, y, d, c;
            cin >> x >> y >> d >> c;
            x--, y--;
            v[x].push_back(data({y, d, c}));
            v[y].push_back(data({x, d, c}));
        }
        // score, velocity, from, to
        priority_queue<pair<double, pair<int, pair<int,int>>>> pq;
        pq.push({-0.0, {0, {s, s}}});
        dp[s][s][0] = 0;
        while(!pq.empty()){
            auto p = pq.top();  pq.pop();
            double cost = -p.F;
            int ve = p.S.F, from = p.S.S.F, pos = p.S.S.S;
            if(dp[from][pos][ve] != cost)    continue;
            for(int dv = -1; dv <= 1; dv++){
                int nv = ve+dv;
                if(nv <= 0) continue;
                for(data d : v[pos]){
                    if(nv > d.u)    continue;
                    int to = d.to;
                    if(to == from)  continue;
                    double ncost = cost + (double)(d.d)/nv;
                    if(dp[pos][to][nv] > ncost){
                        dp[pos][to][nv] = ncost;
                        pq.push({-ncost, {nv, {pos, to}}});
                    }
                }
            }
        }
        double ans = DBL_MAX;
        for(int i = 0; i < n; i++)  if(i != g)  ans = min(ans, dp[i][g][1]);
        if(ans == DBL_MAX)  cout << "unreachable" << endl;
        else                cout << ans << endl;
    }
    return 0;
}
