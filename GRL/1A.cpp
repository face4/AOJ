#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef long long ll;

struct Edge{
    int to, cost;
    Edge() {}
    Edge(int t, int c) : to(t), cost(c) {}
};

#define INF 1ll<<60

int main(){
    int v, e, r;
    scanf("%d %d %d", &v, &e, &r);
    
    vector<vector<Edge>> path(v);

    int s, t, d;
    for(int i = 0; i < e; i++){
        scanf("%d %d %d", &s, &t, &d);
        path[s].push_back(Edge(t,d));
    }

    ll dist[v];
    for(int i = 0; i < v; i++)  dist[i] = INF;
    dist[r] = 0;

    priority_queue<pair<ll,int>> pq;
    for(int i = 0; i < v; i++)  pq.push({-dist[i], i});

    while(!pq.empty()){
        pair<ll,int> now = pq.top(); pq.pop();
        ll cost = -now.first;
        int pos = now.second;
        if(dist[pos] < cost)    continue;

        for(Edge e : path[pos]){
            if(cost + e.cost < dist[e.to]){
                dist[e.to] = cost + e.cost;
                pq.push({-dist[e.to], e.to});
            }
        }
    }

    for(int i = 0; i < v; i++){
        if(dist[i] != INF)  printf("%d\n", dist[i]);
        else                printf("INF\n");
    }

    return 0;
}