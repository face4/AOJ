#include<iostream>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

char mat[100][100];
bool bad[100][100] = {};

int di[8] = {0,0,1,1,1,-1,-1,-1};
int dj[8] = {1,-1,-1,0,1,-1,0,1};

int main(){
    int h, w;
    cin >> h >> w;
    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            bad[i][j] |= mat[i][j]!='-';
            int k = 0;
            if(mat[i][j]=='o')  k = 2;
            if(mat[i][j]=='x')  k = 8;
            for(int l = 0; l < k; l++){
                int ni = i + di[l], nj = j + dj[l];
                if(inRange(ni,0,h)&&inRange(nj,0,w))    bad[ni][nj] = true;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < h; i++)  for(int j = 0; j < w; j++)  ans += !bad[i][j];
    cout << ans << endl;
    return 0;
}
