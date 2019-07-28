#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int MAX_V = 200;

struct edge{
    int to, cap, cost, rev;
};

int V;
vector<edge> G[MAX_V];
int dist[MAX_V];    // 頂点にflowを1流すときのコストの総和
int prevv[MAX_V], preve[MAX_V]; // prev_vertex, prev_edge
const int INF = 1<<30;

void add_edge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1});
}

// flow from s to t, the amount of that is f
int min_cost_flow(int s, int t, int f){
    int res = 0;
    while(f > 0){
        for(int i = 0; i < V; i++)  dist[i] = INF;
        dist[s] = 0;
        bool update = true;
        // bellman-ford
        while(update){
            update = false;
            for(int v = 0; v < V; v++){
                if(dist[v] == INF)  continue;
                for(int i = 0; i < G[v].size(); i++){
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost){
                        dist[e.to] = dist[v] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        update = true;
                    }
                }
            }
        }
        if(dist[t] == INF){
            return -1;
        }
        int d = f;
        // 辺を逆に辿る、流せるだけ流す
        for(int v = t; v != s; v = prevv[v]){
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * dist[t];
        for(int v = t; v != s; v = prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d; // 順方向に流したので-
            G[v][e.rev].cap += d;   // 逆方向に流したので+
        }
    }
    return res;
}

int main(){
    int e, f;
    cin >> V >> e >> f;
    for(int i = 0; i < e; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add_edge(a, b, c, d);
    }
    cout << min_cost_flow(0, V-1, f) << endl;
    return 0;
}