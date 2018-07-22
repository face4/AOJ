#include<iostream>
#include<queue>
using namespace std;

#define N 100
#define INF 1<<21

int fee[N+1][N+1];
int d[N+1];
bool visit[N+1];
int n, k;

int dijkstra(int a, int b){
    for(int i = 0; i < 101; i++){
        d[i] = INF;
        visit[i] = 0;
    }

    d[a] = 0;

    priority_queue<pair<int,int>> pq;

    pq.push({-d[a], a});

    while(!pq.empty()){
        pair<int,int> now = pq.top();
        pq.pop();

        visit[now.second] = true;
        if(-now.first > d[now.second])   continue;

        for(int j = 1; j <= n; j++){
            if(fee[now.second][j] == INF || visit[j])    continue;
            
            if(fee[now.second][j] + d[now.second] < d[j]){
                d[j] = fee[now.second][j] + d[now.second];
                pq.push({-d[j], j});
            }
        }
    }

    return d[b];
}

int main(){
    while(1){
        cin >> n >> k;
        
        if(n + k == 0)  break;

        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 101; j++){
                fee[i][j] = INF;
            }
        }

        int op, a, b, c, d, e;
        for(int i = 0; i < k; i++){
            cin >> op;
            if(op == 1){
                cin >> c >> d >> e;
                fee[c][d] = fee[d][c] = min(fee[c][d], e);
            }else if(op == 0){
                cin >> a >> b;
                int ans = dijkstra(a, b);
                if(ans == INF)  ans = -1;
                cout << ans << endl;
            }
        }
    }
    return 0;
}