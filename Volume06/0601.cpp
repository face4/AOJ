#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

const ll INF = 1ll<<60;

int main(){
    int n, m;
    ll x;
    cin >> n >> m >> x;

    vector<int> h(n);
    vector<pair<int,int>> v[n];
    int a, b, t;

    for(int i = 0; i < n; i++)  cin >> h[i];

    for(int i = 0; i < m; i++){
        cin >> a >> b >> t;
        a--, b--;
        if(h[a]-t >= 0) v[a].push_back({b, t});
        if(h[b]-t >= 0) v[b].push_back({a, t});
    }

    // cost, height, pos
    priority_queue<pair<ll,pair<int, int>>> pq;

    vector<ll> dist(n, INF);
    pq.push({0, {x, 0}});
    ll ans = INF;

    while(!pq.empty()){
        pair<ll,pair<int,int>> now = pq.top();    pq.pop();
        ll cost = -now.first;
        int height = now.second.first;
        int pos = now.second.second;
        if(pos == n-1){
            ans = min(ans, cost + abs(height-h[n-1]));
            continue;
        }
        if(cost >= dist[pos])   continue;
        dist[pos] = cost;
        for(pair<int,int> p : v[pos]){
            int to = p.first, d = p.second;
            ll tmpcost = cost + d;
            int tmpheight = height;
            if(height-d > h[to])    tmpcost += height-d-h[to], tmpheight = h[to];
            else if(height-d < 0)   tmpcost += -(height-d), tmpheight = 0;
            else                    tmpheight -= d;
            if(tmpcost < dist[to]){
                pq.push({-tmpcost, {tmpheight, to}});
            }
        }
    }

    if(ans == INF)   cout << -1 << endl;
    else            cout << ans << endl;

    return 0;
}