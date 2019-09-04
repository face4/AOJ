#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1<<30;

int main(){
    int n, r;
    cin >> n >> r;
    vector<pair<int,int>> v[n];
    for(int i = 0; i < r; i++){
        int s, t, d;
        cin >> s >> t >> d;
        s--, t--;
        v[s].push_back({t, d});
        v[t].push_back({s, d});
    }
    vector<vector<int>> dp(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++){
        priority_queue<pair<int,int>> pq;
        dp[i][i] = 0;
        pq.push({-0, i});
        while(!pq.empty()){
            pair<int,int> p = pq.top();  pq.pop();
            int x = p.second;
            if(dp[i][x] != -p.first)    continue;
            for(pair<int,int> next : v[x]){
                int ni = next.first, ncost = dp[i][x]+next.second;
                if(dp[i][ni] > ncost){
                    dp[i][ni] = ncost;
                    pq.push({-ncost, ni});
                }
            }
        }
    }
    int mad = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mad = max(mad, dp[i][j]);
        }
    }
    vector<bool> ng(n, 0);
    for(int i = 0; i < n; i++){
        vector<bool> visit(n, 0);
        queue<int> q;
        for(int j = i+1; j < n; j++){
            if(dp[i][j] != mad) continue;
            q.push(j);
            visit[j] = true;    ng[j] = true;
        }
        while(!q.empty()){
            int x = q.front();  q.pop();
            for(pair<int,int> next : v[x]){
                if(visit[next.first]) continue;
                if(dp[i][x]-next.second == dp[i][next.first]){
                    visit[next.first] = true;   ng[next.first] = true;
                    q.push(next.first);
                }
            }
        }
    }
    vector<int> res;
    for(int i = 0; i < n; i++){
        if(!ng[i])  res.push_back(i+1);
    }
    cout << res.size() << endl;
    for(int i : res)    cout << i << endl;
    return 0;
}