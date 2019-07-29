#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

const int MAX_V = 202;

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

bool maru[100][100] = {};

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
            if(inRange(prevv[v],0,99)&&inRange(v-100,0,99)) maru[prevv[v]][v-100] = true;
            if(inRange(prevv[v]-100,0,99)&&inRange(v,0,99)) maru[v][prevv[v]-100] = false;
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    V = 202;
    int w[n][n], e[n][n];
    for(int i = 0; i < n*n; i++)    cin >> w[i/n][i%n];
    for(int i = 0; i < n*n; i++)    cin >> e[i/n][i%n];
    char c[n][n];
    int score = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c[i][j];
            if(c[i][j] == 'o'){
                score += e[i][j];
                w[i][j] = -e[i][j];
            }
        }
    }
    int SOURCE = 200, SINK = 201;
    for(int i = 0; i < n; i++){
        add_edge(SOURCE, i, 1, 0);
        add_edge(100+i, SINK, 1, 0);
        for(int j = 0; j < n; j++){
            add_edge(i, 100+j, 1, w[i][j]);
        }
    }
    cout << score + min_cost_flow(SOURCE, SINK, n) << endl;

    vector<int> x, y, z;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(maru[i][j] == (c[i][j]=='o'))    continue;
            x.push_back(i+1);
            y.push_back(j+1);
            z.push_back(c[i][j]=='o');
        }
    }
    string s[2] = {"write", "erase"};
    cout << x.size() << endl;
    for(int i = 0; i < x.size(); i++){
        cout << x[i] << " " << y[i] << " " << s[z[i]] << endl;
    }
    return 0;
}
