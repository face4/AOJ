#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct data{
    int to, cost, p;
};

const int INF = 1<<30;

int main(){
    int n, m, l;
    while(cin >> n >> m >> l, n+m+l){
        vector<data> v[n];
        for(int i = 0; i < m; i++){
            int a, b, d, e;
            cin >> a >> b >> d >> e;
            a--, b--;
            v[a].push_back(data({b, d, e}));
            v[b].push_back(data({a, d, e}));
        }
        vector<vector<int>> dp(n, vector<int>(l+1, INF));
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({-0, {0, l}});
        dp[0][l] = 0;
        while(!pq.empty()){
            auto p = pq.top();  pq.pop();
            int cost = -p.first, pos = p.second.first, money = p.second.second;
            if(dp[pos][money] != cost)  continue;
            for(data d : v[pos]){
                // do not hire
                if(cost+d.p < dp[d.to][money]){
                    dp[d.to][money] = cost + d.p;
                    pq.push({-(cost+d.p), {d.to, money}});
                }
                // hire
                if(money >= d.cost && dp[d.to][money-d.cost] > cost){
                    dp[d.to][money-d.cost] = cost;
                    pq.push({-cost, {d.to, money-d.cost}});
                }
            }
        }
        int ans = INF;
        for(int i = 0; i <= l; i++) ans = min(ans, dp[n-1][i]);
        cout << ans << endl;
    }
    return 0;
}