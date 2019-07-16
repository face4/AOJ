#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int a[1000][1000], x[1000001], y[1000001];
int f[1000][1000] = {};

int main(){
    int h, w;
    cin >> h >> w;
    int a[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
            x[a[i][j]] = i;
            y[a[i][j]] = j;
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            bool ok = true;
            for(int k = 0; k < 4; k++){
                int ni = i+di[k], nj = j+dj[k];
                if(inRange(ni,0,h)&&inRange(nj,0,w)&&a[ni][nj]<a[i][j]) ok = false;
            }
            if(ok)  f[i][j] = a[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= h*w; i++){
        for(int k = 0; k < 4; k++){
            int ni = x[i]+di[k], nj = y[i]+dj[k];
            if(inRange(ni,0,h)&&inRange(nj,0,w)&&a[ni][nj]<a[x[i]][y[i]]){
                if(f[x[i]][y[i]] == 0)  f[x[i]][y[i]] = f[ni][nj];      // 新しく逆フローを流す
                else if(f[x[i]][y[i]] != f[ni][nj]) f[x[i]][y[i]] = -1; // 既に別の場所から逆フローが流れてきている...!
            }
        }
        if(f[x[i]][y[i]] == -1) ans++;
    }
    cout << ans << endl;
    return 0;
}