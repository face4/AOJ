#include<iostream>
using namespace std;

int main(){
    int H, W, h, w;
    cin >> H >> W;
    int A[H][W], B[H][W];
    for(int i = 0; i < H*W; i++)    cin >> A[i/W][i%W];
    for(int i = 0; i < H*W; i++)    cin >> B[i/W][i%W];
    cin >> h >> w;
    int C[h][w];
    for(int i = 0; i < h*w; i++)    cin >> C[i/w][i%w];
    int ans = -1e9;
    for(int i = 0; i <= H-h; i++){
        for(int j = 0; j <= W-w; j++){
            int match = 0, tmp = 0;
            for(int ni = 0; ni < h; ni++){
                for(int nj = 0; nj < w; nj++){
                    match += (B[i+ni][j+nj]==C[ni][nj]);
                    tmp += A[i+ni][j+nj];
                }
            }
            if(match == h*w)    ans = max(ans, tmp);
        }
    }
    if(ans == -1e9) cout << "NA" << endl;
    else            cout << ans << endl;
    return 0;
}