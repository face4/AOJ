#include<iostream>
using namespace std;

static const int MAX = 100;
static const int INF = (1<<21);
int n, m;
int M[MAX][MAX];

int prim(){
    int p[MAX], d[MAX], visit[MAX];

    for(int i = 0; i < n; i++){
        p[i] = -1;
        d[i] = INF;
        visit[i] = 0;
    }

    d[0] = 0;

    while(true){
        int minv = INF;
        int next = -1;
        for(int i = 0; i < n; i++){
            if(minv > d[i] && visit[i] == 0){
                minv = d[i];
                next = i;
            }
        }

        if(next == -1)  break;
        visit[next] = 1;

        for(int i = 0; i < n; i++){
            if(M[next][i] != INF && visit[i] == 0 && d[i] > M[next][i]){
                d[i] = M[next][i];
                p[i] = next;
            }
        }
    }
    
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(p[i] != -1) sum += (M[p[i]][i]/100)-1;
    }

    return sum;
}

int main(){
    while(1){
        scanf("%d\n", &n);
        if(n == 0)  break;

        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                M[i][j] = INF;
            }
        }

        scanf("%d\n" , &m);

        int a, b, d;
        for(int i = 0; i < m; i++){
            scanf("%d,%d,%d\n", &a, &b, &d);
            M[a][b] = M[b][a] = d;
        }

        cout << prim() << endl;
    }

    return 0;
}