#include<iostream>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int h, w, ans;
int mat[20][20];

void dfs(int i, int j, int s){
    if(s >= 10)  return;

    for(int k = 0; k < 4; k++){
        int ni = i+di[k], nj = j+dj[k];
        if(!inRange(ni,0,h) || !inRange(nj,0,w) || mat[ni][nj] == 1)    continue;
        bool valid = true;
        while(mat[ni][nj] != 1){
            if(mat[ni][nj] == 3){
                ans = min(ans, s+1);
                return;
            }
            ni += di[k], nj += dj[k];
            if(!inRange(ni,0,h) || !inRange(nj,0,w)){
                valid = false;
                break;
            }
        }
        if(!valid)  continue;
        mat[ni][nj] = 0;
        dfs(ni-di[k], nj-dj[k], s+1);
        mat[ni][nj] = 1;
    }

}

int main(){
    while(cin >> w >> h, w+h){
        ans = 11;
        int si, sj;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
                if(mat[i][j] == 2)  si = i, sj = j;
            }
        }
        dfs(si, sj, 0);
        cout << (ans == 11 ? -1 : ans) << endl;
    }
    return 0;
}