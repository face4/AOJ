//coding on smartphone
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int di[2][4] = {{0, 0, 1, -1}, {0, 0, 1, -1}};
int dj[2][4] = {{1, -1, 0, 0}, {-1, 1, 0, 0}};

struct data{
    int li, lj, ri, rj;
};

int main(){
    int w, h;
    char c;
    while(cin >> w >> h, w+h){
        bool dp[h][w][h][w];
        int li, lj, ri, rj;
        memset(dp, 0, sizeof(dp));
        char mat[2][h][w];
        for(int i = 0; i < h; i++){
            for(int k = 0; k < 2; k++){
                for(int j = 0; j < w; j++){
                    cin >> mat[k][i][j];
                    if(mat[k][i][j]=='L')   li = i, lj = j;
                    if(mat[k][i][j]=='R')   ri = i, rj = j;
                }
                //if(k == 0) cin >> c;   // space
            }
        }
        bool valid = false;
        queue<data> q;
        q.push(data({li,lj,ri,rj}));
        dp[li][lj][ri][rj] = true;
        while(!q.empty()){
            data d = q.front(); q.pop();
            for(int k = 0; k < 4; k++){
                int nli = d.li+di[0][k], nlj = d.lj+dj[0][k];
                int nri = d.ri+di[1][k], nrj = d.rj+dj[1][k];
                if(!inRange(nli,0,h)||!inRange(nlj,0,w)||mat[0][nli][nlj]=='#') nli = d.li, nlj = d.lj;
                if(!inRange(nri,0,h)||!inRange(nrj,0,w)||mat[1][nri][nrj]=='#') nri = d.ri, nrj = d.rj;
                int target = (mat[0][nli][nlj]=='%') + (mat[1][nri][nrj]=='%');
                if(target == 2){
                    valid = true;
                    break;
                }
                if(target == 0 && !dp[nli][nlj][nri][nrj]){
                    dp[nli][nlj][nri][nrj] = true;
                    q.push(data({nli,nlj,nri,nrj}));
                }
            }
            if(valid)   break;
        }
        cout << (valid ? "Yes" : "No") << endl;
    }
    return 0;
}


