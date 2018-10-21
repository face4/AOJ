#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct edge{
    int to, cap, rev;
};

#define MAX_V 1002
vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size()-1});
}

int dfs(int v, int t, int f){
    if(v == t)  return f;

    used[v] = true;
    for(int i = 0; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }

    return 0;
}

const int INF = 1<<29;

int max_flow(int s, int t){
    int flow = 0;
    while(1){
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if(f == 0)  return flow;
        flow += f;
    }
}

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

void init(){
    for(int i = 0; i < MAX_V; i++)  G[i].clear();
    memset(used, 0, sizeof(used));
}

int main(){
    int m, n;
    while(cin >> m >> n, m+n){
        init();
        int b[m], r[n];
        for(int i = 0; i < m; i++)  cin >> b[i], add_edge(0, i+1, 1);
        for(int i = 0; i < n; i++)  cin >> r[i], add_edge(501+i, 1001, 1);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(gcd(b[i], r[j]) != 1)    add_edge(i+1, 501+j, 1);
            }
        }

        cout << max_flow(0, 1001) << endl;
    }
    return 0;
}