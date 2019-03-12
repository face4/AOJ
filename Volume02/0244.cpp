#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        vector<pair<int,int>> v[n];
        int a, b, c;
        while(m-- > 0){
            cin >> a >> b >> c;
            a--, b--;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
        vector<vector<int>> dp(2, vector<int>(n, 1<<30));
        priority_queue<pair<int, pair<int,int>>> pq;
        pq.push({-0, {0, 0}});
        // 0 - before using ticket, 1 - after 
        while(!pq.empty()){
            auto p = pq.top();  pq.pop();
            int cost = -p.first, pos = p.second.first, stat = p.second.second;
            if(dp[stat][pos] <= cost)   continue;
            dp[stat][pos] = cost;
            for(pair<int,int> next : v[pos]){
                if(dp[stat][next.first] > cost + next.second){
                    pq.push({-(cost+next.second), {next.first, stat}});
                }
                if(stat == 0){
                    int npos = next.first;
                    for(pair<int,int> q : v[npos]){
                        if(dp[1][q.first] > cost){
                            pq.push({-cost, {q.first, 1}});
                        }
                    }
                }
            }
        }
        cout << min(dp[0][n-1], dp[1][n-1]) << endl;
    }
    return 0;
}