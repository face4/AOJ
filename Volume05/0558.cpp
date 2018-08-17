#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define inRange(x, a, b) a <= x && x < b

int h, w, n;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

char mat[1000][1000];
vector<pair<int,int>> v(10);

int bfs(pair<int,int> x , pair<int,int> y){
    queue<pair<pair<int,int>, int>> s;
    bool visit[1000][1000] = {};

    s.push({x, 0});
    int ret = 0;

    while(!s.empty()){
        pair<pair<int,int>,int> p = s.front();  s.pop();
        if(visit[p.first.first][p.first.second])    continue;

        if(p.first.first == y.first && p.first.second == y.second){
            ret = p.second;
            break;
        }

        visit[p.first.first][p.first.second] = true;

        for(int i = 0; i < 4; i++){
            int nx = p.first.first + dx[i];
            int ny = p.first.second + dy[i];
            if(inRange(nx, 0, h) && inRange(ny, 0, w) && mat[nx][ny] != 'X' && !visit[nx][ny])  
                s.push({{nx,ny}, p.second+1});
        }
    }

    return ret;
}

int main(){
    cin >> h >> w >> n;
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == '.' || mat[i][j] == 'X')    continue;
            if(mat[i][j] == 'S')    v[0]= {i,j};
            v[mat[i][j]-'0'] = {i,j};
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += bfs(v[i], v[i+1]);
    }

    cout << ans << endl;

    return 0;
}