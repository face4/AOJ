// 解説を読みました...
#include<iostream>
#include<cstring>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int dp[30][30][901];

int main(){
    memset(dp, 0x3f, sizeof(dp));
    int h, w;
    cin >> h >> w;
    int mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }
    dp[0][0][0] = 0;
    for(int step = 0; step < h*w; step++){
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(dp[i][j][step] > 1e9)    continue;
                for(int k = 0; k < 4; k++){
                    int ni = i+di[k], nj = j+dj[k];
                    if(!inRange(ni,0,h)||!inRange(nj,0,w))  continue;
                    int nc = dp[i][j][step]+2*step*mat[ni][nj]+mat[ni][nj];
                    dp[ni][nj][step+1] = min(dp[ni][nj][step+1], nc);
                }
            }
        }
    }
    int ans = 1<<30;
    for(int i = 0; i < h*w; i++)    ans = min(ans, dp[h-1][w-1][i]);
    cout << ans << endl;
    return 0;
}