#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> t(n);
    for(int i = 0; i < n; i++)  cin >> t[i];
    vector<pair<int,int>> v[n];
    for(int i = 0; i < m; i++){
        int a, b, d;
        cin >> a >> b >> d;
        a--, b--;
        v[a].push_back({b, d});
        v[b].push_back({a, d});
    }
    vector<vector<int>> dp(n, vector<int>(401, 1<<30));
    priority_queue<pair<int, pair<int,int>>> pq;
    pq.push({-0, {0, -x}});
    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        int cost = -p.first, pos = p.second.first, tmp = p.second.second;
        if(dp[pos][tmp+200] <= cost)    continue;
        dp[pos][tmp+200] = cost;
        for(pair<int,int> q : v[pos]){
            int next = q.first, ntmp = tmp, ncost = cost + q.second;
            if(tmp < 0){
                if(tmp+q.second < 0 && t[next]==2)  continue;
                ntmp = min(0, tmp+q.second);
            }else if(tmp > 0){
                if(tmp-q.second > 0 && t[next]==0)  continue;
                ntmp = max(0, tmp-q.second);
            }
            if(t[next] == 2)    ntmp = x;
            if(t[next] == 0)    ntmp = -x;
            if(ncost < dp[next][ntmp+200])  pq.push({-ncost, {next, ntmp}});
        }
    }
    int ans = 1<<30;
    for(int tmp = 0; tmp < 401; tmp++)  ans = min(ans, dp[n-1][tmp]);
    cout << ans << endl;
    return 0;
}