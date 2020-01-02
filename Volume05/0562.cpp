#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pii> v[n+1];
    vector<pair<pii,int>> vp;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vp.push_back({{a,b},c});
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i = 0; i < k; i++){
        int x;  cin >> x;
        v[0].push_back({x,0});
    }
    vector<int> dp(n+1, 1<<30);
    dp[0] = 0;
    priority_queue<pii> pq;
    pq.push({-0, 0});
    while(!pq.empty()){
        pii p = pq.top();   pq.pop();
        int pos = p.second, cost = -p.first;
        if(dp[pos] != cost) continue;
        for(pii q : v[pos]){
            int next = q.first;
            if(dp[next] > dp[pos]+q.second){
                dp[next] = dp[pos]+q.second;
                pq.push({-dp[next], next});
            }
        }
    }
    int ret = 0;
    for(int i = 0; i < m; i++){
        int a = vp[i].first.first, b = vp[i].first.second, c = vp[i].second;
        ret = max(ret, (dp[a]+dp[b]+c+1)/2);
    }
    cout << ret << endl;
    return 0;
}