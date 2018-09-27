#include<iostream>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int main(){
    int w, h;
    while(cin >> w >> h, w+h){
        int mat[h][w];
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
            }
        }

        int islands = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(mat[i][j] == 0)  continue;
                islands++;
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    pair<int,int> now = q.front(); q.pop();
                    int ni = now.first, nj = now.second;
                    if(mat[ni][nj] == 0)    continue;
                    mat[ni][nj] = 0;
                    for(int k = 0; k < 8; k++){
                        int di = ni + dx[k], dj = nj + dy[k];
                        if(inRange(di, 0, h) && inRange(dj, 0, w) && mat[di][dj]){
                            q.push({di,dj});
                        }
                    }
                }
            }
        }

        cout << islands << endl;
    }
    
    return 0;
}