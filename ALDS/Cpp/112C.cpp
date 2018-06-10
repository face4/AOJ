#include<iostream>
#include<queue>
#include<vector>
using namespace std;

static const int MAX = 10000;
static const int INF = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
vector<pair<int,int>> adj[MAX];

void dijkstra(){
    int color[MAX], d[MAX];

    for(int i = 0; i < n; i++){
        color[i] = WHITE;
        d[i] = INF;
    }

    d[0] = 0;

    // pair<vに到達するまでのスコア、v>
    priority_queue<pair<int,int>> pq;
    pq.push({0,0});
    color[0] = GRAY;

    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int u = p.second;
        
        color[u] = BLACK;
        if(d[u] < p.first*(-1)) continue;

        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j].first;
            if(color[v] == BLACK)   continue;
            if(d[v] > d[u] + adj[u][j].second){
                d[v] = d[u] + adj[u][j].second;
                pq.push({d[v]*(-1), v});
                color[v] = GRAY;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << i << " " << d[i] << endl;
    }
}

int main(){
   int u, k, v, c;

   cin >> n;
   for(int i = 0; i < n; i++){
       cin >> u >> k;
       for(int j = 0; j < k; j++){
           cin >> v >> c;
           adj[u].push_back({v,c});
       }
   }

   dijkstra();

   return 0;
}