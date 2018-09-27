#include<iostream>
#include<stack>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int h, w;
    while(cin >> w >> h, w+h){
        char mat[h][w];
        int x, y;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
                if(mat[i][j] == '@')    y = i, x = j, mat[i][j] = '.';
            }
        }

        stack<pair<int,int>> s;
        s.push({y,x});

        int ans = 0;
        while(!s.empty()){
            pair<int,int> now = s.top();    s.pop();
            if(mat[now.first][now.second] == '#')   continue;
            if(mat[now.first][now.second] == '.')   ans++;
            mat[now.first][now.second] = '#';
            for(int k = 0; k < 4; k++){
                int ny = now.first + dy[k];
                int nx = now.second + dx[k];
                if(inRange(ny, 0, h) && inRange(nx,0,w) && mat[ny][nx] == '.'){
                    s.push({ny, nx});
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}