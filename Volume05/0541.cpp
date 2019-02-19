#include<iostream>
#include<vector>
using namespace std;

int di[2] = {1, 0};
int dj[2] = {0, 1};

int main(){
    int h, w, n;
    while(cin >> h >> w >> n, h+w+n){
        int mat[h][w], dp[h+1][w+1];
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
                dp[i][j] = 0;
            }
        }
        dp[0][0] = n-1;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(dp[i][j] == 0)   continue;
                int tmp = mat[i][j];
                mat[i][j] = (mat[i][j]+dp[i][j])%2;
                int ni = i+di[tmp], nj = j+dj[tmp];
                dp[ni][nj] += (dp[i][j]+1)/2;
                ni = i+di[1-tmp], nj = j+dj[1-tmp];
                dp[ni][nj] += dp[i][j]/2;
            }
        }
        int ansi = 0, ansj = 0;
        while(ansi != h && ansj != w){
            if(mat[ansi][ansj] == 0)    ansi++;
            else                        ansj++;
        }
        cout << ansi+1 << " " << ansj+1 << endl;
    }
    return 0;
}