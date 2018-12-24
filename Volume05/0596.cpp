#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int INF = 1<<30;

bool adj[5001][5001];

int main(){
    int n, k;
    cin >> n >> k;

    int c[n], r[n];
    for(int i = 0; i < n; i++)  cin >> c[i] >> r[i];

    vector<int> path[n];
    int a, b;

    for(int i = 0; i < k; i++){
        cin >> a >> b;
        a--, b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    // make adjacency list O(n^2)
    for(int i = 0; i < n; i++){
        queue<pair<int,int>> q;
        q.push({i, r[i]});
        while(!q.empty()){
            pair<int,int> p = q.front();    q.pop();
            if(adj[i][p.first]) continue;
            adj[i][p.first] = true;
            if(p.second == 0)   continue;
            for(int next : path[p.first]){
                if(!adj[i][next])   q.push({next, p.second-1});
            }
        }
    }

    int d[n];
    for(int i = 0; i < n; i++)  d[i] = INF;

    // cost, pos
    priority_queue<pair<int,int>> pq;
    pq.push({0, 0});

    // worst O(n^2)
    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int cost = -p.first;
        
        if(cost >= d[p.second])  continue;
        
        d[p.second] = cost;
        
        if(p.second == n-1){
            cout << cost << endl;
            return 0;
        }

        for(int next = 0; next < n; next++){
            if(!adj[p.second][next])    continue;
            if(d[next] > cost+c[p.second])  pq.push({-(cost+c[p.second]), next});
        }

    }

}