#include<iostream>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int w, h;
    while(cin >> w >> h, w+h){
        char mat[h][w];
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
            }
        }

        int black = 0, white = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(mat[i][j] != '.')    continue;
                queue<pair<int,int>> q;
                q.push({i,j});
                bool f = false, g = false;
                int area = 0;
                while(!q.empty()){
                    pair<int,int> now = q.front(); q.pop();
                    int y = now.first, x = now.second;
                    if(mat[y][x] != '.'){
                        if(mat[y][x] == 'W')    f = true;
                        if(mat[y][x] == 'B')    g = true;
                        continue;
                    }
                    area++;
                    mat[y][x] = 'x';
                    for(int k = 0; k < 4; k++){
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if(inRange(ny, 0, h) && inRange(nx, 0, w) && mat[ny][nx] != 'x'){
                            q.push({ny,nx});
                        }
                    }
                }

                if(f && !g) white += area;
                if(g && !f) black += area;
            }
        }

        cout << black << " " << white << endl;

    }
    return 0;
}