#include<iostream>
using namespace std;

static const int MAX = 100;
static const int INF = 1<<21;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];

int prim(){
    int u, minv;
    int d[MAX], p[MAX], color[MAX];

    for(int i = 0; i < n; i++){
        d[i] = INF;
        p[i] = -1;
        color[i] = WHITE;
    }

    d[0] = 0;

    while(1){
        minv = INF;
        u = -1;

        for(int i = 0; i < n; i++){
            if(color[i] != BLACK && minv > d[i]){
                u = i;
                minv = d[i];
            }
        }

        if(u == -1) break;

        color[u] = BLACK;
        for(int v = 0; v < n; v++){
            if(M[u][v] != INF && color[v] != BLACK && d[v] > M[u][v]){
                d[v] = M[u][v];
                p[v] = u;
                color[v] = GRAY;
            }
        }
    }

    int sum = 0;

    for(int v = 0; v < n; v++){
        if(p[v] != -1)  sum += M[p[v]][v];
    }

    return sum;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            if(x == -1) M[i][j] = INF;
            else        M[i][j] = x;
        }
    }

    cout << prim() << endl;
    
    return 0;
}