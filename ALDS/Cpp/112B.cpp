#include<iostream>
using namespace std;

static const int MAX = 100;
static const int INF = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];

void dijkstra(){
    int d[MAX], color[MAX];
    int u, minc;

    for(int i = 0; i < n; i++){
        d[i] = INF;
        color[i] = WHITE;
    }

    d[0] = 0;

    while(1){
        minc = INF;
        u = -1;
        for(int i = 0; i < n; i++){
            if(color[i] != BLACK && minc > d[i]){
                minc = d[i];
                u = i;
            }
        }

        if(minc == INF) break;

        color[u] = BLACK;

        for(int v = 0; v < n; v++){
            if(M[u][v] != INF && color[v] != BLACK){
                if(d[u] + M[u][v] < d[v]){
                    d[v] = d[u] + M[u][v];
                    color[v] = GRAY;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << i << " " << d[i] << endl;
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            M[i][j] = INF;
        }
    }

    for(int i = 0; i < n; i++){
        int from, k, to, c;
        cin >> from >> k;
        for(int j = 0; j < k; j++){
            cin >> to >> c;
            M[from][to] = c;
        }
    }

    dijkstra();

    return 0;
}