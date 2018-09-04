#include<iostream>
using namespace std;

#define N 90
#define inRange(x,a,b) a <= x && x < b

int mat[N][N] = {};
bool used[N][N] = {};
int di[4] = {-1,0,0,1};
int dj[4] = {0,1,-1,0};
int h, w, ans;

void dfs(int i, int j, int score){
    ans = max(ans, score);
    used[i][j] = true;
    for(int k = 0; k < 4; k++){
        int ni = i + di[k];
        int nj = j + dj[k];
        if(inRange(ni, 0, h) && inRange(nj, 0, w) && !used[ni][nj] && mat[ni][nj]){
            dfs(ni, nj, score+1);
        }
    }
    used[i][j] = false;
}

int main(){
    while(cin >> w >> h){
        if(w + h == 0)  break;
        ans = 0;

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
            }
        }

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(mat[i][j]){
                    dfs(i, j, 1);
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}