#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, m, l, k, a, h;
    while(cin >> n >> m >> l >> k >> a >> h, n){
        vector<bool> aid(n, 0);
        while(l-- > 0){
            int x;  cin >> x;
            aid[x] = true;
        }
        vector<pair<int,int>> v[n];
        while(k-- > 0){
            int x, y, t;
            cin >> x >> y >> t;
            v[x].push_back({y,t});
            v[y].push_back({x,t});
        }
        vector<vector<int>> dp(n, vector<int>(m+1, 1<<30));
        priority_queue<pair<int, pair<int,int>>> pq;
        pq.push({0, {a, m}});
        dp[a][m] = 0;
        int ans = 1<<30;
        while(!pq.empty()){
            auto p = pq.top();  pq.pop();
            int cost = -p.first, pos = p.second.first, fre = p.second.second;
            if(dp[pos][fre] != cost)    continue;
            dp[pos][fre] = cost;
            if(pos == h){
                ans = cost;
                break;
            }
            for(pair<int,int> next : v[pos]){
                int npos = next.first, ncost = next.second;
                if(fre >= ncost && dp[npos][fre-ncost] > cost+ncost)    dp[npos][fre-ncost] = cost+ncost, pq.push({-(cost+ncost), {npos, fre-ncost}});
                if(aid[pos]){
                    for(int j = max(fre, ncost); j <= m; j++){
                        if(dp[npos][j-ncost] > cost+ncost+j-fre)    dp[npos][j-ncost] = cost+ncost+j-fre, pq.push({-(cost+ncost+j-fre), {npos, j-ncost}});
                    }
                }
            }
        }
        if(ans == 1<<30)    cout << "Help!" << endl;
        else                cout << ans << endl;
    }
    return 0;
}