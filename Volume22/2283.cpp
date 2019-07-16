#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n+m){
        string s, t, g;
        cin >> s >> t >> g;
        map<string, vector<pair<string,int>>> ma;
        for(int i = 0; i < m; i++){
            string a, b;
            int c, d;
            cin >> a >> b >> c >> d;
            ma[a].push_back({b, c/40+d});
            ma[b].push_back({a, c/40+d});
        }
        map<string,int> dp;
        for(auto p : ma) dp[p.first] = 1<<30;
        dp[s] = 0;
        priority_queue<pair<int,string>> pq;
        pq.push({-0, s});
        while(!pq.empty()){
            auto p = pq.top();  pq.pop();
            string pos = p.second;
            int cost = -p.first;
            if(dp[pos] != cost) continue;
            for(auto next : ma[pos]){
                int ncost = cost + next.second;
                string npos = next.first;
                if(dp[npos] > ncost){
                    dp[npos] = ncost;
                    pq.push({-ncost, npos});
                }
            }
        }
        int ans = dp[t];
        for(auto p : ma) dp[p.first] = 1<<30;
        dp[t] = 0;
        pq.push({-0, t});
        while(!pq.empty()){
            auto p = pq.top();  pq.pop();
            string pos = p.second;
            int cost = -p.first;
            if(dp[pos] != cost) continue;
            for(auto next : ma[pos]){
                int ncost = cost + next.second;
                string npos = next.first;
                if(dp[npos] > ncost){
                    dp[npos] = ncost;
                    pq.push({-ncost, npos});
                }
            }
        }
        ans += dp[g];
        cout << ans << endl;
    }
    return 0;
}
