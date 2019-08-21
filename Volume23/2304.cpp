#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int infact[300][300] = {};

struct edge{
    int to, cap, rev;
};

#define MAX_V 300
vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size()-1});
}

// v...target vertex, t...end vertex, f...maximum flow 
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
                infact[v][e.to] = 1;
                infact[e.to][v] = -1;
                return d;
            }
        }
    }

    return 0;
}

const int INF = 1<<29;

// maxflow from s to t
int max_flow(int s, int t){
    int flow = 0;
    while(1){
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if(f == 0)  return flow;
        flow += f;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int v[n][n];
    for(int i = 0; i < n*n; i++)    v[i/n][i%n] = 0;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        add_edge(a[i], b[i], 1);
        add_edge(b[i], a[i], 1);
        v[a[i]][b[i]] = 1;
        v[b[i]][a[i]] = -1;
    }
    int s, t;
    cin >> s >> t;
    cout << max_flow(--s, --t) << endl;
    vector<int> ans;
    for(int i = 0; i < m; i++){
        if(v[a[i]][b[i]]*infact[a[i]][b[i]] == -1)  ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    for(int val : ans)  cout << val << endl;
    return 0;
}