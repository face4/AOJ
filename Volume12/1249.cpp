#include<iostream>
#include<cstring>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)

int dx[13] = {1,0,0,1,1,0,-1,-1, 0,1,-1, 1, 1};
int dy[13] = {0,1,0,1,0,1, 1, 0,-1,1, 1,-1, 1};
int dz[13] = {0,0,1,0,1,1, 0, 1, 1,1, 1, 1,-1};

int main(){
    int n, m, p;
    while(cin >> n >> m >> p, n+m+p){
        int peg[n][n][n];
        memset(peg, -1, sizeof(peg));

        int x[p], y[p];
        for(int i = 0; i < p; i++)  cin >> x[i] >> y[i], x[i]--, y[i]--;

        string ans = "Draw";
        int turn = -1;
        
        for(int i = 0; i < p; i++){
            int z;
            for(z = 0;;z++) if(peg[x[i]][y[i]][z] == -1)    break;
            peg[x[i]][y[i]][z] = i%2;

            for(int k = 0; k < 13; k++){
                int cont = 1;
                
                int zx = x[i]+dx[k], zy = y[i]+dy[k], zz = z+dz[k];
                while(inRange(zx, 0, n) && inRange(zy, 0, n) && inRange(zz, 0, n) && peg[zx][zy][zz] == peg[x[i]][y[i]][z]){
                    cont++;
                    zx += dx[k], zy += dy[k], zz += dz[k];
                }
                
                zx = x[i]-dx[k], zy = y[i]-dy[k], zz = z-dz[k];
                while(inRange(zx, 0, n) && inRange(zy, 0, n) && inRange(zz, 0, n) && peg[zx][zy][zz] == peg[x[i]][y[i]][z]){
                    cont++;
                    zx -= dx[k], zy -= dy[k], zz -= dz[k];
                }

                if(cont >= m){
                    if(i % 2 == 0)  ans = "Black";
                    else            ans = "White";
                    turn = i+1;
                    break;
                }
            }

            if(ans != "Draw")   break;
        }

        if(ans != "Draw")   cout << ans << " " << turn << endl;
        else                cout << ans << endl;
    }
    return 0;
}