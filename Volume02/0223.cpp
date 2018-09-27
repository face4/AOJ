#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define inRange(x,a,b) (a <= x && x < b)

bool visit[50][50][50][50];

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

typedef pair<pair<int,int>, pair<int,int>> P;

int main(){
    int w, h, tx, ty, hx, hy;
    while(cin >> w >> h, w){
        memset(visit, 0, sizeof(visit));
        cin >> tx >> ty >> hx >> hy;
        tx--, ty--, hx--, hy--;
        
        int mat[h][w];
        rep(i, h) rep(j, w) cin >> mat[i][j];

        queue<pair<P, int>> q;
        q.push({{{ty,tx},{hy,hx}}, 0});

        int ans = -1;
        while(!q.empty()){
            pair<P,int> p = q.front();  q.pop();
            if(p.second > 100)  break;
            int a = p.first.first.first, b = p.first.first.second;
            int c = p.first.second.first, d = p.first.second.second;
            if(a == c && b == d){
                ans = p.second;
                break;
            }
            if(visit[a][b][c][d])   continue;

            visit[a][b][c][d] = true;

            for(int k = 0; k < 4; k++){
                int na = a + dx[k], nb = b + dy[k];
                int nc = c + dx[(k+2)%4], nd = d + dy[(k+2)%4];
                /*
                cout << a << ", " << b << " -> " << na << ", " << nb << endl;
                cout << c << ", " << d << " -> " << nc << ", " << nd << endl;
*/
                if(!inRange(na,0,h) || !inRange(nb,0,w) || mat[na][nb] == 1){
                    na = a, nb = b;
                }
                if(!inRange(nc,0,h) || !inRange(nd,0,w) || mat[nc][nd] == 1){
                    nc = c, nd = d;
                }

                if(!visit[na][nb][nc][nd]){
                    q.push({{{na,nb},{nc,nd}}, p.second+1});
                }
            }
        }

        if(ans == -1)   cout << "NA" << endl;
        else            cout << ans << endl;
    }

    return 0;
}