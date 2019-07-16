#include<iostream>
#include<vector>
#include<queue>
#include<cctype>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)
int di[4] = {-1, 0, 1, 0};
int dj[4] = { 0, 1, 0,-1};

// memory, row, column, direction
bool visit[16][20][20][4] = {};

struct data{
    int m, i, j, d;
};

int main(){
    int h, w;
    cin >> h >> w;
    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }
    queue<data> q;
    q.push(data({0, 0, 0, 1}));
    while(!q.empty()){
        data x = q.front(); q.pop();
        int m = x.m, i = x.i, j = x.j, d = x.d;
        if(mat[i][j] == '@'){
            cout << "YES" << endl;
            return 0;
        }
        if(mat[i][j] == '<')    d = 3;
        if(mat[i][j] == 'v')    d = 2;
        if(mat[i][j] == '>')    d = 1;
        if(mat[i][j] == '^')    d = 0;
        if(mat[i][j] == '_')    if(m == 0)  d = 1; else d = 3;
        if(mat[i][j] == '|')    if(m == 0)  d = 2; else d = 0;
        if(isdigit(mat[i][j]))  m = mat[i][j]-'0';
        if(mat[i][j] == '+')    m = (m+1)%16;
        if(mat[i][j] == '-')    m = (m+15)%16;

        if(mat[i][j] == '?'){
            for(int dir = 0; dir < 4; dir++){
                int ni = (i+di[dir]+h)%h, nj = (j+dj[dir]+w)%w;
                if(!visit[m][ni][nj][dir]){
                    visit[m][ni][nj][dir] = true;
                    q.push(data({m,ni,nj,dir}));
                }
            }
        }else{
            int ni = (i+di[d]+h)%h, nj = (j+dj[d]+w)%w;
            if(!visit[m][ni][nj][d]){
                visit[m][ni][nj][d] = true;
                q.push(data({m,ni,nj,d}));
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}