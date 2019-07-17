#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

const int INF = INT_MAX;

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    if(s > t){
        cout << 0 << endl;
        return 0;
    }
    vector<int> d(n);
    for(int i = 0; i < n; i++)  cin >> d[i];
    vector<int> v[n];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[--a].push_back(--b);
    }
    vector<int> dp(n, INF);
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i <= s; i++){
        for(int next : v[i])    pq.push({-d[next],next});
    }
    int to = s;
    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        int cost = -p.first, pos = p.second;
        if(cost >= dp[pos] || pos <= to) continue;
        dp[pos] = cost;
        if(pos >= t){
            cout << dp[pos] << endl;
            return 0;
        }
        while(to < pos){
            to++;
            for(int next : v[to]){
                int ncost = cost + d[next];
                if(dp[next] > ncost) pq.push({-ncost, next});
            }
        }
    }
}