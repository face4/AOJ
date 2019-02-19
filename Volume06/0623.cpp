#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int main(){
    int n, m, k, s;
    ll p, q;
    cin >> n >> m >> k >> s >> p >> q;
    
    vector<int> v[n+1], z(n+1, 0);
    while(k-- > 0){
        int x; cin >> x;
        z[x] = 2;
        v[0].push_back(x);
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<pair<int,int>> que;
    if(s){
        for(int tmp : v[0]) for(int next : v[tmp]) que.push({next, 1});
    }
    while(!que.empty()){
        auto pa = que.front(); que.pop();
        int pos = pa.first, cost = pa.second;
        if(z[pos] == 1)  continue;
        if(z[pos] != 2) z[pos] = 1;
        for(int next : v[pos]){
            if(z[next] != 1 && cost != s)    que.push({next, cost+1});
        }
    }

    vector<ll> dist(n+1, (1ll<<60));

    priority_queue<pair<ll,int>> pq;
    pq.push({-0, 1});

    while(!pq.empty()){
        auto pa = pq.top(); pq.pop();
        ll cost = -pa.first; int pos = pa.second;
        if(dist[pos] <= cost)   continue;
        dist[pos] = cost;
        for(int next : v[pos]){
            if(z[next] == 2)    continue;
            ll tmpc = cost + (z[next] == 0 ? p : q);
            if(tmpc < dist[next])   pq.push({-tmpc, next});
        }
    }

    cout << dist[n] - (z[n] == 0 ? p : q) << endl;

    return 0;
}