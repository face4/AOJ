#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int w, h, xs, ys, xg, yg;
int mat[102][102];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

void init(){
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            mat[i][j] = 0;
        }
    }
}

bool bfs(){
    if(mat[xs][ys] == 0 || mat[xg][yg] == 0)    return false;

    int c = mat[xs][ys];
    stack<pair<int,int>> s;
    s.push({xs,ys});
    bool visit[102][102] = {};
    
    while(!s.empty()){
        pair<int,int> now = s.top(); 
        s.pop();
        if(now.first == xg && now.second == yg){
            return true;
        }
        
        visit[now.first][now.second] = true;
        
        for(int i = 0; i < 4; i++){
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            
            if(mat[nx][ny] == c && !visit[nx][ny]){
                s.push({nx,ny});
            }
        }
    }
    
    return false;
}


int main(){
    while(1){
        cin >> w >> h;
        if(w + h == 0)  break;
        cin >> ys >> xs >> yg >> xg;
        
        init();
        
        int n;
        cin >> n;
        
        int c, d, x, y;
        while(n-- > 0){
            cin >> c >> d >> y >> x;
            if(d == 0){
                for(int i = 0; i < 2; i++){
                    for(int j = 0; j < 4; j++){
                        mat[x+i][y+j] = c;
                    }
                }
            }else if(d == 1){
                for(int i = 0; i < 4; i++){
                    for(int j = 0; j < 2; j++){
                        mat[x+i][y+j] = c;
                    }
                }
            }
        }

        if(bfs())   cout << "OK" << endl;
        else        cout << "NG" << endl;
    }

    return 0;
}
