#include<iostream>
using namespace std;

static const int INF = 1<<21;
int n, m, a, b, c, d, s, g, v, p;
int mat[21][21];

void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    scanf("%d", &m);

    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 21; j++){
            mat[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++){
        scanf("%d,%d,%d,%d", &a, &b, &c, &d);
        mat[a][b] = c;
        mat[b][a] = d;
    }
    
    scanf("%d,%d,%d,%d", &s, &g, &v, &p);

    floyd();

    printf("%d\n", v-(mat[s][g]+mat[g][s]+p));

    return 0;
}