#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;

const ll INF = 1ll<<60;

int main(){
    int n, m;
    ll c;
    scanf("%d %d %lld", &n, &m, &c);

    map<int, map<int,int>> v;
    int a, b, d;
    ll sum = 0;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &d);
        a--, b--;
        v[a][b] = d;
        v[b][a] = d;
        sum += d;
    }

    // dijkstra
    vector<ll> dist(n, INF);
    priority_queue<pair<ll,int>> pq;
    pq.push({-0, 0});

    while(!pq.empty()){
        pair<ll,int> p = pq.top();  pq.pop();
        ll cost = -p.first;
        int pos = p.second;
        if(cost >= dist[pos])   continue;
        dist[pos] = cost;
        for(pair<int,int> edge : v[pos]){
            if(cost + edge.second < dist[edge.first]){
                pq.push({-(cost + edge.second), edge.first});
            }
        }
    }

    vector<pair<ll,int>> vp;
    for(int i = 1; i < n; i++){
        vp.push_back({dist[i], i});
    }
    sort(vp.begin(), vp.end());

    int len = vp.size();
    int cur = 0;
    set<int> used;
    used.insert(0);
    ll ans = sum;

    while(cur < len){
        ll x = vp[cur].first;
        vector<int> add;
        add.push_back(vp[cur].second);
        while(cur+1 < len && vp[cur+1].first == x){
            cur++;
            add.push_back(vp[cur].second);
        }
        for(int del : add){
            for(auto e : v[del]){
                int to = e.first, cost = e.second;
                if(used.count(to)){
                    sum -= cost;
                }
            }
            used.insert(del);
        }
        ans = min(ans, c*x + sum);
        cur++;
    }

    cout << ans << endl;

    return 0;
}